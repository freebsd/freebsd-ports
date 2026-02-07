--- src/core/fastlock.h.orig	2025-09-01 19:50:34 UTC
+++ src/core/fastlock.h
@@ -99,7 +99,7 @@ typedef volatile int fl_lock_t;
 #endif /* NOSMP */
 #define membar_getlock()
 
-#elif defined(__CPU_ppc) || defined(__CPU_ppc64)
+#elif defined(__CPU_ppc) || defined(__CPU_ppc64) || defined(__CPU_powerpc) || defined(__CPU_ppc64) || defined(__CPU_powerpc64le)
 #ifndef NOSMP
 #define membar_getlock() asm volatile("lwsync \n\t" : : : "memory");
 #else
@@ -228,7 +228,7 @@ inline static int tsl(fl_lock_t *lock)
 				 : "cc", "memory");
 
 
-#elif defined(__CPU_ppc) || defined(__CPU_ppc64)
+#elif defined(__CPU_ppc) || defined(__CPU_ppc64) || defined(__CPU_powerpc) || defined(__CPU_ppc64) || defined(__CPU_powerpc64le)
 	asm volatile("1: \n\t"
 #ifdef SPIN_OPTIMIZE
 				 "   lwzx %0, 0, %2 \n\t"
@@ -394,7 +394,7 @@ inline static void release_lock(fl_lock_t *lock)
 	asm volatile(" stlr %w1, %0 \n\t" : "=Q"(*lock) : "r"(0) : "memory");
 
 
-#elif defined(__CPU_ppc) || defined(__CPU_ppc64)
+#elif defined(__CPU_ppc) || defined(__CPU_ppc64) || defined(__CPU_powerpc) || defined(__CPU_ppc64) || defined(__CPU_powerpc64le)
 	asm volatile(
 			/* "sync\n\t"  lwsync is faster and will work
 			 *             here too
