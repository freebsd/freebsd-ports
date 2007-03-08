http://math-atlas.sourceforge.net/errata.html
Misdetection of nregs causes some x86 installs to go awry.

--- tune/blas/gemm/mmsearch.c	Mon Dec 22 09:11:57 2003
+++ tune/blas/gemm/mmsearch.c	Wed Mar  7 02:42:27 2007
@@ -822,6 +822,10 @@
    int lat, NO1D=0;
    double mf0, mf1, mf;
 
+   #if defined(ATL_GAS_x8632) || defined(ATL_GAS_x8664)
+      return(0);
+   #endif
+
    if (pre == 'z') pre = 'd';
    else if (pre == 'c') pre = 's';
 
