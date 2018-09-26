#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstructuraGenerica.h"
#define TAMANIO 10
#define OCUPADO 0
#define LIBRE 1



int eGen_init( eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idGenerica= 0;
        }
    }
    return retorno;
}

int eGen_buscarLugarLibre(eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eGen_siguienteId(eGenerica listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                if(listado[i].idGenerica>retorno)
                {
                    retorno=listado[i].idGenerica;
                }

            }
        }
    }

    return retorno+1; // Busco el ID mayor, le suma 1 y lo retorna. Esta operacion permite obtener el siguiente id
}


int eGen_buscarPorId(eGenerica listado[],int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idGenerica == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



int eGen_mostrarUno(eGenerica parametro)
{
    printf("\n %s - %d - %d",parametro.nombre,parametro.idGenerica,parametro.estado);
    return 0;
}

int eGen_mostrarListado(eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {

                eGen_mostrarUno(listado[i]);
            }
        }
    }
    return retorno;
}


int eGen_mostrarListadoConBorrados(eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            eGen_mostrarUno(listado[i]);
        }
    }
    return retorno;
}




int eGen_alta(eGenerica  listado[],int limite)
{
    int retorno = -1;
    //char nombre[50];
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eGen_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = eGen_siguienteId(listado,limite);

            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            //{
            retorno = 0;
            strcpy(listado[indice].nombre,"juan");
            listado[indice].idGenerica = id;
            listado[indice].estado = OCUPADO;
            //}
        }
    }
    return retorno;
}


int eGen_baja(eGenerica listado[], int limite, int id)
{
    int retorno = -1;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eGen_buscarPorId(listado, limite, id);

        if(indice >= 0)
        {
            listado[indice].estado = LIBRE;
        }
        else
        {
            printf("No se encontro el Id");
        }

    }
    return retorno;
}


int eGen_modificacion(eGenerica listado[],int limite, int id)
{
    int retorno = -1;
    char nombre[50];
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eGen_buscarPorId(listado, limite, id);

        if(indice >= 0)
        {
            puts("Introduzca nuevo nombre: ");
            gets(nombre);
            validaLargoCadena(nombre, indice, 50);
            strcpy(listado[indice].nombre, nombre);
        }
        else
        {
            printf("No se encontro el Id");
        }

    }
    return retorno;
}


int validaLargoCadena(char nombre[], int indice, int tamano)
{

    while(strlen(nombre) >= tamano)
    {
        puts("Nombre demasiado largo. Ingrese otro: ");
        gets(nombre);
    }
    return 0;
}
