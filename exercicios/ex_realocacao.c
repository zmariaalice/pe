#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);
void recebe(float *p, int tam);
void imprime(float *p, int tam);
void altera(float *p, int tam);

int main() {

  float *ptr = NULL;

  aloca(&ptr, 10);
  recebe(ptr, 10);
  imprime(ptr, 10);
  altera(ptr, 10);
  imprime(ptr, 10);
  return 0;
}

void aloca(float **p, int tam) {
  if (((*p = (float *)realloc(*p, tam * sizeof(float)))) == NULL) {
    printf("Erro na alocacao!");
    exit(1);
  }
  printf("\nFunçao aloca - Endereco: %u", *p);
}

void recebe(float *p, int tam) {
  int i;
  printf("\nFuncao recebe - Digite os valores: \n");
  for (i = 0; i < tam; i++) {
    printf("Endereco de %u - Valor = ", p + i);
    scanf("%f", p + i);
  }
}

void imprime(float *p, int tam) {
  int i;
  printf("\nFuncao imprimir - Mostra os valores\n");
  for (i = 0; i < tam; i++) {
    printf("Endereco: %u - Valor = %2.f\n", p + i, *(p + i));
  }
}

void altera(float *p, int tam) {
  int i;
  for (i = 0; i < tam; i++) {
    *(p + i) += 30;
  }
}