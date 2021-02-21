--- biotsavart.cc.orig	2021-02-21 21:52:50 UTC
+++ biotsavart.cc
@@ -128,7 +128,7 @@ by a vortex segment joining @code{@var{x}(j,1:3)} and 
           Matrix X = args(1).matrix_value ();
           RowVector dir = args(2).row_vector_value ();
           if (CP.cols () == 3 
-              && X.cols () == 3 && dir.length () == 3)
+              && X.cols () == 3 && dir.numel () == 3)
             {
               octave_idx_type m = CP.rows (), n = X.rows ();
               NDArray vi (dim_vector (m, n, 3));
@@ -148,7 +148,7 @@ by a vortex segment joining @code{@var{x}(j,1:3)} and 
           Matrix X = args(2).matrix_value ();
           RowVector dir = args(3).row_vector_value ();
           if (CP.cols () == 3 && CN.cols () == 3 && CP.rows () == CN.rows ()
-              && X.cols () == 3 && dir.length () == 3)
+              && X.cols () == 3 && dir.numel () == 3)
             {
               octave_idx_type m = CP.rows (), n = X.rows ();
               Matrix vn (m, n);
