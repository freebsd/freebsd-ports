--- src/smack1.c.orig	2021-01-31 09:13:30 UTC
+++ src/smack1.c
@@ -119,8 +119,7 @@
 #elif defined(__FreeBSD__)
 #include <sys/types.h>
 #include <machine/cpufunc.h>
-#define __rdtsc rdtsc
-#if (__ARM_ARCH >= 6)  // V6 is the earliest arch that has a standard cyclecount
+#if (__ARM_ARCH >= 6 && __ARM_ARCH <= 7)  // V6 is the earliest arch that has a standard cyclecount
 unsigned long long rdtsc(void)
 {
   uint32_t pmccntr;
@@ -138,6 +137,10 @@ unsigned long long rdtsc(void)
   }
   return 0;
 }
+#elif defined(__aarch64__)
+#define __rdtsc() 0
+#else
+#define __rdtsc rdtsc
 #endif
 #elif defined (__llvm__)
 #if defined(i386) || defined(__i386__)
