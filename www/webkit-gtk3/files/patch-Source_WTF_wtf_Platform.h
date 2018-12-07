This patch reportedly fixes build for ARM and powerpc64. See PR 208569

--- Source/WTF/wtf/Platform.h.orig	2016-04-10 06:48:36 UTC
+++ Source/WTF/wtf/Platform.h
@@ -119,11 +119,16 @@
 
 /* CPU(PPC64) - PowerPC 64-bit Big Endian */
 #if (  defined(__ppc64__)      \
-    || defined(__PPC64__))     \
+    || defined(__PPC64__)      \
+    || defined(__powerpc64__))   \
     && defined(__BYTE_ORDER__) \
     && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
 #define WTF_CPU_PPC64 1
 #define WTF_CPU_BIG_ENDIAN 1
+#define ENABLE_ASSEMBLER 0
+#define ENABLE_JIT 0
+#define ENABLE_YARR_JIT 0
+#define ENABLE_SAMPLING_PROFILER 0
 #endif
 
 /* CPU(PPC64) - PowerPC 64-bit Little Endian */
@@ -218,6 +218,7 @@
 #elif defined(__ARM_ARCH_6__) \
     || defined(__ARM_ARCH_6J__) \
     || defined(__ARM_ARCH_6K__) \
+    || defined(__ARM_ARCH_6KZ__) \
     || defined(__ARM_ARCH_6Z__) \
     || defined(__ARM_ARCH_6ZK__) \
     || defined(__ARM_ARCH_6T2__) \
