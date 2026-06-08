--- aeron-client/src/main/c/concurrent/aeron_thread.c.orig	2025-11-24 19:20:55 UTC
+++ aeron-client/src/main/c/concurrent/aeron_thread.c
@@ -336,7 +336,7 @@ void proc_yield(void)
 
 void proc_yield(void)
 {
-#if !defined(AERON_CPU_ARM)
+#if !defined(AERON_CPU_ARM) && !defined(AERON_CPU_PPC64)
     __asm__ volatile("pause\n": : : "memory");
 #endif
 }
