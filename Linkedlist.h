#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstddef>
#include <iostream>
#include <stdlib.h>
#include<stdio.h>
using namespace std;

 ///LinkedList


template <class T>
class Nodo{
    public:
        T dato;
        Nodo <T> *pSig;
        Nodo <T>(){
            pSig = NULL;
        }
        Nodo<T>(T dato){
            this -> dato = dato;
            pSig = NULL;
        }

};
///Clase LinkedList

template <class T>
class Linkedlist{
    public:
        ///
        Linkedlist();
        ///Destructor de la lista
        /*
        ~Linkedlist (){
            Nodo<T> *p = pInicio;
            while(pInicio!=NULL){
                borraFinal();
            }
        }*/
        ///Meter al inicio de la lista
        void meterInicio(T dato);
        void meterFinal(T dato);
        void borraInicion();
        void borraFinal();
        ///Metodo impirmeList
        void imprimirLista();
        void reverse();
        void deletes(int iX,int iY);

        void shift(int iDato);
        Linkedlist<T>operator += (const Linkedlist<T> &l);

        bool operator == (const Linkedlist <T> &l);

        int sumacuadrados(Nodo<T>* p);
        int sumacuad();
        int minValor();
        int menores(Nodo<T>* p,int iX);

    private:
        Nodo<T> *pInicio;

};
#endif // LINKEDLIST_H
template <class T>
Linkedlist<T> :: Linkedlist(){
    pInicio = NULL;
}
///Add a node at the beginning
template <class T>
void Linkedlist<T> :: meterInicio(T dato){
            Nodo <T> *p;
            p = new Nodo<T>(dato);
            p->pSig = pInicio;
            pInicio = p;
}
///Add a node at the end
template <class T>
 void Linkedlist<T> :: meterFinal(T dato){
            Nodo <T> *p = new Nodo<T>(dato);
            Nodo <T> *pR = pInicio;
            while(pR ->pSig!=NULL ){
                pR = pR ->pSig;
            }
            pR->pSig = p;
}
///Erase the first node from a LinkedList
template <class T>
void  Linkedlist<T> :: borraInicion(){
            if(pInicio != NULL){
                Nodo<T> *p=pInicio;
                pInicio = pInicio;
            }
}
///Display a LinkedList
template <class T>
void Linkedlist<T> :: borraFinal(){
            if(pInicio!= NULL){
                if(pInicio->pSig = NULL){
                    Nodo<T> *p = pInicio;
                    delete p;
                    pInicio=NULL;
                }
                else {
                    Nodo <T> *p = pInicio;
                    Nodo<T> *q = NULL;
                    while (p->pSig != NULL){
                        q = p;
                        p = p->pSig;
                    }
                    delete p;
                    q -> pSig == NULL;
                }
            }
}

///Display a LinkedList
template <class T>
void Linkedlist<T> :: imprimirLista(){
            Nodo <T> * p = pInicio;
            while (p !=NULL){
                cout<<p->dato<<" ";
                p = p->pSig;

            }
}

///Reverse all the content from a Linkedlist
template <class T>
void Linkedlist<T> :: reverse(){
            if(pInicio!=NULL){
                if(pInicio->pSig != NULL){
                    Nodo<T> *p = pInicio->pSig;
                    Nodo<T> *q = pInicio;
                    q->pSig = NULL;
                while( p != NULL){
                    q = p;
                    p = p->pSig;
                    q->pSig = pInicio;
                    pInicio = q;
                }
                }
            }
}

///This function makes a slipping of (int iDato) boxes, if int iDato is 2, the first box will be the third position, the second will be the fourth position
template <class T>
void Linkedlist<T> :: shift(int iDato){
            if(pInicio != NULL){
                if(pInicio->pSig != NULL){
                    if(iDato>0){
                        Nodo<T> *q;
                        Nodo<T> *p = pInicio;
                        for(int iCont = 0; iCont<iDato;iCont++){
                            while(p->pSig != NULL){
                                q=p;
                                p=p->pSig;
                            }
                            p->pSig = pInicio;
                            pInicio = p;
                            q->pSig =NULL;
                        }
                    }
                    else if(iDato<0){
                        iDato = abs(iDato);
                        Nodo<T> *q;
                        Nodo<T> *p = pInicio;
                        while(p->pSig!=NULL){
                            p=p->pSig;
                        }
                        for(int iCont = 0; iCont<iDato;iCont++){
                            q = pInicio;
                            pInicio = pInicio->pSig;
                            q->pSig = NULL;
                            p->pSig = q;
                            p = q;
                        }
                    }
                }
            }
}

/// This function ERASE iX(number)nodes starting from the iY position
template <class T>
void Linkedlist<T> :: deletes(int iX,int iY){
            if(pInicio !=NULL){
                int iCant = 0;
                Nodo<T> *p = pInicio;
                Nodo<T> *q = pInicio;
                while( p!=NULL ){
                    iCant++;
                    p = p->pSig;
                }
                p = pInicio;
                for(int iCont = 0; iCont<iY;iCont++){
                    q = p;
                    p = p->pSig;
                }
                if(p == pInicio){
                    for(int iCont = 0; iCont<iX;iCont++){
                        if(pInicio != NULL){
                            pInicio = pInicio->pSig;
                            delete p;
                            p = pInicio;
                        }
                        else{
                            iCont = iX +1;
                            pInicio = NULL;
                        }
                    }
                }
                else{
                    for(int iCont = 0; iCont<iX;iCont++){
                        if( p !=NULL ){
                            q->pSig = p->pSig;
                            delete p;
                            p = q->pSig;
                        }
                        else{
                            iCont = iX +1;
                        }
                    }
                }
            }
}
///This function concatenates two linkedlist
template <class T>
Linkedlist<T> Linkedlist <T> :: operator += (const Linkedlist<T> &l){
            Nodo<T> *p = pInicio;
            Nodo<T> *z = l.pInicio;
            pInicio = p;
            if(pInicio != NULL && l.pInicio != NULL){
                while (p->pSig !=NULL){
                    p = p->pSig;
                }
                while(z != NULL){
                    p->pSig = new Nodo <T>(z->dato);
                    z = z->pSig;
                    p = p->pSig;
                }
            }
            return *this;
}
///This function verifies if two linkedlist has the same content and the name lenght
template <class T>
bool Linkedlist <T> ::operator == (const Linkedlist <T> &l){
            Nodo<T> *p = pInicio;
            int iX = 0;
            Nodo<T> *q = l.pInicio;
            int iY = 0;
            if(pInicio !=NULL && l.pInicio != NULL){
            while(p!=NULL){
                iX++;
                p = p->pSig;
            }
            while(q!=NULL){
                iY++;
                q = q->pSig;
            }
            if(iY == iX){
            while(p != NULL && q!=NULL){
                if(p->dato != q->dato){
                    return false;
                }
                p = p->pSig;
                q = q->pSig;
            }
            return true;
            }
            else{
                return false;
            }
        }

        else{
            return false;
            }
}

template <class T>
int Linkedlist <T> :: sumacuad(){

    return sumacuadrados(pInicio);

}
/// This functions add the square of all the values from a LinkedList (Recursiveness)
template <class T>
int Linkedlist <T> :: sumacuadrados(Nodo<T> *p){

    if(p->pSig!=NULL){
        cout<<p->dato<<endl;
        return (p->dato*p->dato) + sumacuadrados(p->pSig);
    }
    else{
        return (p->dato*p->dato);
    }

}

template <class T>
int Linkedlist <T> :: minValor(){

    int iX = pInicio->dato;
    return menores(pInicio,iX);

}
/// This functions makes a search,looking the minimum value from a LinkedList (Recursiveness)
template <class T>
int Linkedlist <T> :: menores(Nodo<T> *p,int iX){

    if(p!=NULL){
        if(p->dato<iX){
            iX = p->dato;
        }
        p=p->pSig;
        return menores(p,iX);
    }
    else{
        return iX;
    }
}

