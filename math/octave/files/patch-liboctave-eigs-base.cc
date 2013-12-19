--- liboctave/eigs-base.cc.orig	2013-02-21 21:19:24.000000000 +0100
+++ liboctave/eigs-base.cc	2013-11-22 20:19:19.000000000 +0100
@@ -3832,7 +3832,7 @@
                              bool cholB = 0, int disp = 0, int maxit = 300);
 #endif
 
-#ifndef _MSC_VER
+#if !defined(_MSC_VER) && !defined(__clang__)
 template static octave_idx_type
 lusolve (const SparseMatrix&, const SparseMatrix&, Matrix&);
 
