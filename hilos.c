#include <studio.h>
#include <pthread.h>

void *printMessage(void*arg){
  int threadld = *((int*)arg);
  printf("Hello %d\n", threadld);
  pthread_exit(NULL);
}

int main() {
    int NUM_THREADS = 20;
    
    pthread_t threads[NUM_THREADS];
    int threadIds[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        threadIds[i] = i;
        pthread_create(&threads[i], NULL, printMessage, (void *)&threadIds[i]);
    }

    pthread_exit(NULL);
    printf("Main thread\n");

    return 0;
}
