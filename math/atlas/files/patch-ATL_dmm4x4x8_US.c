http://math-atlas.sourceforge.net/errata.html
Error in UltraSPARC cleanup

--- tune/blas/gemm/CASES/ATL_dmm4x4x8_US.c	Mon Dec 22 09:12:04 2003
+++ tune/blas/gemm/CASES/ATL_dmm4x4x8_US.c	Wed Mar  7 02:57:37 2007
@@ -272,7 +272,7 @@
 !
 !  For K == 1, we never enter the loop at all
 !
-#if (KB != 2)
+#if (KB != 8)
    #if KB == 0
         subcc   Kstart, %g0, %g0
         bz      KDRAIN
