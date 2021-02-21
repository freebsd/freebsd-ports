--- tbasisfun.cc.orig	2021-02-21 22:37:09 UTC
+++ tbasisfun.cc
@@ -156,7 +156,7 @@ TBASISFUN: Compute a B- or T-Spline basis function, an
   RowVector N(u.cols ());
   double *Nptr = N.fortran_vec ();
 
-  if (! args(2).is_cell ())
+  if (! args(2).iscell ())
     {
 
       double p = args(1).idx_type_value ();
