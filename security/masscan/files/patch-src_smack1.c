--- src/smack1.c.orig	2021-01-31 09:13:30 UTC
+++ src/smack1.c
@@ -119,9 +119,8 @@
 #elif defined(__FreeBSD__)
 #include <sys/types.h>
 #include <machine/cpufunc.h>
-#define __rdtsc rdtsc
-#if (__ARM_ARCH >= 6)  // V6 is the earliest arch that has a standard cyclecount
-unsigned long long rdtsc(void)
+#if (__ARM_ARCH >= 6 && __ARM_ARCH <= 7)  // V6 is the earliest arch that has a standard cyclecount
+unsigned long long __rdtsc(void)
 {
   uint32_t pmccntr;
   uint32_t pmuseren;
@@ -138,6 +137,32 @@ unsigned long long rdtsc(void)
   }
   return 0;
 }
+#elif defined(__aarch64__)
+#define __rdtsc() 0
+#elif defined(__powerpc64__)
+unsigned long long __rdtsc(void)
+{
+  unsigned long long rval;
+  __asm__ __volatile__("mfspr %%r3, 268": "=r" (rval));
+  return rval;
+}
+#elif defined(__powerpc__)
+unsigned long long __rdtsc(void)
+{
+  unsigned int tmp;
+  union { unsigned long long complete; unsigned int part[2]; } ticks;
+  __asm__ ("0:"
+            "mftbu %[hi32]\n"
+            "mftb %[lo32]\n"
+            "mftbu %[tmp]\n"
+            "cmpw %[tmp],%[hi32]\n"
+            "bne 0b\n"
+            : [hi32] "=r"(ticks.part[0]), [lo32] "=r"(ticks.part[1]),
+            [tmp] "=r"(tmp));
+  return ticks.complete;
+}
+#else
+#define __rdtsc rdtsc
 #endif
 #elif defined (__llvm__)
 #if defined(i386) || defined(__i386__)
