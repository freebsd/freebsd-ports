--- src/real/prim.h.orig	2019-07-18 20:14:48 UTC
+++ src/real/prim.h
@@ -106,7 +106,7 @@ int __kernel_rem_pio2(double* x, double* y, int e0, in
 /* Detect other BE CPUs */
 #if !defined(__IEEE_LITTLE_ENDIAN) && !defined(__IEEE_BIG_ENDIAN)
 #if defined(PPCCPU)      || defined(__PPC__) || \
-    defined(__powerpc__) || defined(__powerpc64__) \
+    defined(__powerpc__) || defined(__powerpc64__) || \
     defined(__mips__) || defined(__mips)
 #define __IEEE_BIG_ENDIAN
 #endif
