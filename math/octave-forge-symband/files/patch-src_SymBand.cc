--- src/SymBand.cc.orig	2021-02-21 22:29:47 UTC
+++ src/SymBand.cc
@@ -366,7 +366,7 @@ DEFUN_DLD (SBSolve, args, , "[...] = SBSolve (...)\n\
     return retval;
   }
 
-  if ( A_arg.is_real_type() && B_arg.is_real_type() ) {
+  if ( A_arg.isreal() && B_arg.isreal() ) {
 
     Matrix A= A_arg.matrix_value();
     Matrix B= B_arg.matrix_value();
