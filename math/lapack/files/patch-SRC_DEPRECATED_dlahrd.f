--- SRC/DEPRECATED/dlahrd.f.orig	2024-12-03 11:39:11 UTC
+++ SRC/DEPRECATED/dlahrd.f
@@ -231,8 +231,9 @@
 *
 *           w := T**T *w
 *
-            CALL DTRMV( 'Upper', 'Transpose', 'Non-unit', I-1, T, LDT,
-     $                  T( 1, NB ), 1 )
+* Patch from https://github.com/Reference-LAPACK/lapack/pull/1093
+            CALL DTRMV( 'Upper', 'Transpose', 'Non-unit', I-1,
+     $                  T, LDT, T( 1, NB ), 1 )
 *
 *           b2 := b2 - V2*w
 *
@@ -270,8 +271,9 @@
 *        Compute T(1:i,i)
 *
          CALL DSCAL( I-1, -TAU( I ), T( 1, I ), 1 )
-         CALL DTRMV( 'Upper', 'No transpose', 'Non-unit', I-1, T, LDT,
-     $               T( 1, I ), 1 )
+* Patch from https://github.com/Reference-LAPACK/lapack/pull/1093
+         CALL DTRMV( 'Upper', 'No transpose', 'Non-unit', I-1,
+     $               T, LDT, T( 1, I ), 1 )
          T( I, I ) = TAU( I )
 *
    10 CONTINUE
