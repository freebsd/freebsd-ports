--- __surrogates__.cc.orig	2015-08-14 22:25:52 UTC
+++ __surrogates__.cc
@@ -34,14 +34,21 @@ FOR INTERNAL USE ONLY"
 #include <octave/f77-fcn.h>
 #include <octave/Cell.h>
 
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
   F77_FUNC (ts_surrogates, TS_SURROGATES)
-            (const double *xx, const octave_idx_type& nmaxp,
-             const octave_idx_type& mcmax, const octave_idx_type& imax,
-             const octave_idx_type& ispec, const double& seed, double *output,
-             octave_idx_type& iterations, double& rel_discrepency);
+            (const double *xx, const F77_INT& nmaxp,
+             const F77_INT& mcmax, const F77_INT& imax,
+             const F77_INT& ispec, const double& seed, double *output,
+             F77_INT& iterations, double& rel_discrepency);
 }
 
 
@@ -59,15 +66,15 @@ DEFUN_DLD (__surrogates__, args, nargout
     // Assigning inputs
       Matrix input          = args(0).matrix_value ();
       octave_idx_type nsur  = args(1).idx_type_value ();
-      octave_idx_type imax  = args(2).idx_type_value ();
-      octave_idx_type ispec = args(3).idx_type_value ();
+      F77_INT imax          = TO_F77_INT (args(2).idx_type_value ());
+      F77_INT ispec         = TO_F77_INT (args(3).idx_type_value ());
       double seed           = args(4).double_value ();
 
       if (! error_state)
         {
 
-          octave_idx_type nmaxp = input.rows ();
-          octave_idx_type mcmax = input.columns ();
+          F77_INT nmaxp = TO_F77_INT (input.rows ());
+          F77_INT mcmax = TO_F77_INT (input.columns ());
 
           Cell surro_data (dim_vector (nsur,1));
           Matrix surro_tmp (input.dims ());
@@ -75,7 +82,7 @@ DEFUN_DLD (__surrogates__, args, nargout
 
           for (octave_idx_type i = 0; i < nsur; i++)
             {
-              octave_idx_type it_tmp;
+              F77_INT it_tmp;
               double rel_discrepency_tmp;
 
               F77_XFCN (ts_surrogates, TS_SURROGATES,
