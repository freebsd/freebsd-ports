--- src/lace.h.orig	2021-07-12 11:27:04 UTC
+++ src/lace.h
@@ -293,7 +293,11 @@ void lace_yield(WorkerP *__lace_worker, Task *__lace_d
 #endif
 
 #ifndef mfence
+#if defined(__amd64__) || defined(__i386__)
 #define mfence() { asm volatile("mfence" ::: "memory"); }
+#elif defined(__powerpc__)
+#define mfence() { asm volatile("sync" ::: "memory"); }
+#endif
 #endif
 
 /* Compiler specific branch prediction optimization */
