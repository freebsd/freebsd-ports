armv6/v7:
See PR 222612

Add proper architecture name:
  https://gcc.gnu.org/ml/gcc-patches/2015-06/msg01679.html

--- Source/WTF/wtf/Platform.h.orig	2017-06-04 20:16:06 UTC
+++ Source/WTF/wtf/Platform.h
@@ -105,11 +105,15 @@
 
 /* CPU(PPC64) - PowerPC 64-bit Big Endian */
 #if (  defined(__ppc64__)      \
-    || defined(__PPC64__))     \
+    || defined(__PPC64__)      \
+    || defined(__powerpc64__)) \
     && defined(__BYTE_ORDER__) \
     && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
 #define WTF_CPU_PPC64 1
 #define WTF_CPU_BIG_ENDIAN 1
+#define ENABLE_ASSEMBLER 0
+#define ENABLE_JIT 0
+#define ENABLE_SAMPLING_PROFILER 0
 #endif
 
 /* CPU(PPC64) - PowerPC 64-bit Little Endian */
@@ -226,6 +230,7 @@
 #elif defined(__ARM_ARCH_6__) \
     || defined(__ARM_ARCH_6J__) \
     || defined(__ARM_ARCH_6K__) \
+    || defined(__ARM_ARCH_6KZ__) \
     || defined(__ARM_ARCH_6Z__) \
     || defined(__ARM_ARCH_6ZK__) \
     || defined(__ARM_ARCH_6T2__) \
@@ -272,6 +277,7 @@
 
 #elif defined(__ARM_ARCH_6J__) \
     || defined(__ARM_ARCH_6K__) \
+    || defined(__ARM_ARCH_6KZ__) \
     || defined(__ARM_ARCH_6Z__) \
     || defined(__ARM_ARCH_6ZK__) \
     || defined(__ARM_ARCH_6M__)
