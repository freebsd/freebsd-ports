armv6/v7:
See PR 222612

Add proper architecture name:
  https://gcc.gnu.org/ml/gcc-patches/2015-06/msg01679.html

--- Source/WTF/wtf/Platform.h.orig	2020-03-04 17:16:37 UTC
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
@@ -135,6 +139,9 @@
     && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
 #define WTF_CPU_PPC 1
 #define WTF_CPU_BIG_ENDIAN 1
+#define ENABLE_ASSEMBLER 0
+#define ENABLE_JIT 0
+#define ENABLE_SAMPLING_PROFILER 0
 #endif
 
 /* CPU(SH4) - SuperH SH-4 */
@@ -226,6 +233,7 @@
 #elif defined(__ARM_ARCH_6__) \
     || defined(__ARM_ARCH_6J__) \
     || defined(__ARM_ARCH_6K__) \
+    || defined(__ARM_ARCH_6KZ__) \
     || defined(__ARM_ARCH_6Z__) \
     || defined(__ARM_ARCH_6ZK__) \
     || defined(__ARM_ARCH_6T2__) \
@@ -273,6 +281,7 @@
 
 #elif defined(__ARM_ARCH_6J__) \
     || defined(__ARM_ARCH_6K__) \
+    || defined(__ARM_ARCH_6KZ__) \
     || defined(__ARM_ARCH_6Z__) \
     || defined(__ARM_ARCH_6ZK__) \
     || defined(__ARM_ARCH_6M__)
