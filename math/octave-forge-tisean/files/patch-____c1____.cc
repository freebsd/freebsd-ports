--- __c1__.cc.orig	2015-08-14 22:25:52 UTC
+++ __c1__.cc
@@ -34,17 +34,24 @@ FOR INTERNAL USE ONLY"
 #include <octave/f77-fcn.h>
 #include <octave/oct-map.h>
 
+#if defined (OCTAVE_HAVE_F77_INT_TYPE)
+#  define TO_F77_INT(x) octave::to_f77_int (x)
+#else
+typedef octave_idx_type F77_INT;
+#  define TO_F77_INT(x) (x)
+#endif
+
 extern "C"
 {
   F77_RET_T
   F77_FUNC (d1, D1)
-            (const octave_idx_type& nmax, const octave_idx_type& mmax,
-             const octave_idx_type& nxx, const double *y,
-             const octave_idx_type& delay, const octave_idx_type& m,
-             const octave_idx_type& ncmin, const double& pr,
+            (const F77_INT& nmax, const F77_INT& mmax,
+             const F77_INT& nxx, const double *y,
+             const F77_INT& delay, const F77_INT& m,
+             const F77_INT& ncmin, const double& pr,
              double& pln, double& eln, 
-             const octave_idx_type& nmin, const octave_idx_type& kmax,
-             const octave_idx_type& iverb);
+             const F77_INT& nmin, const F77_INT& kmax,
+             const F77_INT& iverb);
 
   F77_RET_T
   F77_FUNC (rand, RAND)
@@ -66,23 +73,23 @@ DEFUN_DLD (__c1__, args, nargout, HELPTE
     {
     // Assigning inputs
       Matrix input           = args(0).matrix_value ();
-      octave_idx_type mindim = args(1).idx_type_value ();
-      octave_idx_type maxdim = args(2).idx_type_value ();
-      octave_idx_type delay  = args(3).idx_type_value ();
-      octave_idx_type tmin   = args(4).idx_type_value ();
-      octave_idx_type cmin   = args(5).idx_type_value ();
+      F77_INT mindim         = TO_F77_INT (args(1).idx_type_value ());
+      F77_INT maxdim         = TO_F77_INT (args(2).idx_type_value ());
+      F77_INT delay          = TO_F77_INT (args(3).idx_type_value ());
+      F77_INT tmin           = TO_F77_INT (args(4).idx_type_value ());
+      F77_INT cmin           = TO_F77_INT (args(5).idx_type_value ());
       double resolution      = args(6).double_value ();
       double seed            = args(7).double_value ();
-      octave_idx_type kmax   = args(8).idx_type_value ();
+      F77_INT kmax           = TO_F77_INT (args(8).idx_type_value ());
       bool verbose           = args(9).bool_value ();
-      octave_idx_type iverb  = verbose;
+      F77_INT iverb          = TO_F77_INT (verbose);
 
 
       if (! error_state)
         {
 
-          octave_idx_type lines_read   = input.rows (); //nmax in d1()
-          octave_idx_type columns_read = input.columns ();
+          F77_INT lines_read   = TO_F77_INT (input.rows ()); //nmax in d1()
+          F77_INT columns_read = TO_F77_INT (input.columns ());
 
 
           dim_vector dv (maxdim - mindim + 1, 1);
@@ -94,7 +101,7 @@ DEFUN_DLD (__c1__, args, nargout, HELPTE
           // Seed the rand() function for d1()
           F77_XFCN (rand, RAND, (sqrt(seed)));
 
-          for (octave_idx_type m = mindim; m <= maxdim; m++)
+          for (F77_INT m = mindim; m <= maxdim; m++)
             {
               octave_scalar_map tmp (keys);
               tmp.setfield ("dim", m);
