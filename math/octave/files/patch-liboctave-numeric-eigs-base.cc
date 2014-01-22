--- liboctave/numeric/eigs-base.cc.orig	2014-01-20 05:36:55.000000000 -0700
+++ liboctave/numeric/eigs-base.cc	2014-01-20 05:37:23.000000000 -0700
@@ -3849,7 +3849,7 @@
                              int disp = 0, int maxit = 300);
 #endif
 
-#ifndef _MSC_VER
+#if !defined(_MSC_VER) && !defined(__clang__)
 template octave_idx_type
 lusolve (const SparseMatrix&, const SparseMatrix&, Matrix&);
 
