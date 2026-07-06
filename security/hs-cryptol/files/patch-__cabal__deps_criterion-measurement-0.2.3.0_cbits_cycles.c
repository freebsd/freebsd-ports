--- _cabal_deps/criterion-measurement-0.2.3.0/cbits/cycles.c.orig	2001-09-09 01:46:40 UTC
+++ _cabal_deps/criterion-measurement-0.2.3.0/cbits/cycles.c
@@ -68,6 +68,15 @@
   return result;
 }
 
+#elif powerpc64le_HOST_ARCH || powerpc64_HOST_ARCH
+
+StgWord64 criterion_rdtsc(void)
+{
+  StgWord64 ret;
+  __asm__ __volatile__ ("mfspr %0, 268" : "=r"(ret));
+  return ret;
+}
+
 #else
 
 #error Unsupported OS/architecture/compiler!
