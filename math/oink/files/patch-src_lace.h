--- src/lace.h.orig	2021-07-10 20:56:55 UTC
+++ src/lace.h
@@ -17,6 +17,11 @@
  */
 
 #include <unistd.h>
+#ifdef __cplusplus
+#include <atomic>
+#else
+#include <stdatomic.h>
+#endif
 #include <stdint.h>
 #include <stdio.h>
 #include <pthread.h> /* for pthread_t */
@@ -293,7 +298,11 @@ void lace_yield(WorkerP *__lace_worker, Task *__lace_d
 #endif
 
 #ifndef mfence
-#define mfence() { asm volatile("mfence" ::: "memory"); }
+#ifdef __cplusplus
+#define mfence() std::atomic_thread_fence(std::memory_order_seq_cst)
+#else
+#define mfence() atomic_thread_fence(memory_order_seq_cst)
+#endif
 #endif
 
 /* Compiler specific branch prediction optimization */
