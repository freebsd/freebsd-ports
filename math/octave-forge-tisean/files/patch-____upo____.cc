--- __upo__.cc.orig	2015-08-14 22:25:52 UTC
+++ __upo__.cc
@@ -33,18 +33,24 @@ FOR INTERNAL USE ONLY"
 #include <octave/oct.h>
 #include <octave/f77-fcn.h>
 
+#if defined (OCTAVE_HAVE_F77_INT_TYPE)
+#  define TO_F77_INT(x) octave::to_f77_int (x)
+#else
+typedef octave_idx_type F77_INT;
+#  define TO_F77_INT(x) (x)
+#endif
 
 extern "C"
 {
   F77_RET_T
   F77_FUNC (ts_upo, TS_UPO)
-            (const int& m, const double& eps,
+            (const F77_INT& m, const double& eps,
              const double& frac, const double& teq,
              const double& tdis, const double& h,
-             const double& tacc, const int& iper,
-             const int& icen, const int& lines_read,
+             const double& tacc, const F77_INT& iper,
+             const F77_INT& icen, const F77_INT& lines_read,
              double* in_out1, double* olens,
-             double* orbit_data, const int& sizedat,
+             double* orbit_data, const F77_INT& sizedat,
              double* accuracy, double* stability);
 }
 
@@ -63,22 +69,22 @@ DEFUN_DLD (__upo__, args, nargout, HELPT
     {
     // Assigning inputs
       NDArray in_out1 = args(0).array_value();
-      int m           = args(1).int_value();
+      F77_INT m       = TO_F77_INT (args(1).int_value());
       double eps      = args(2).double_value();
       double frac     = args(3).double_value();
       double teq      = args(4).double_value();
       double tdis     = args(5).double_value();
       double h        = args(6).double_value();
       double tacc     = args(7).double_value();
-      int iper        = args(8).int_value();
-      int icen        = args(9).int_value();
+      F77_INT iper    = TO_F77_INT (args(8).int_value());
+      F77_INT icen    = TO_F77_INT (args(9).int_value());
 
 
 
       if (! error_state)
         {
 
-          int lines_read = in_out1.numel();
+          F77_INT lines_read = TO_F77_INT (in_out1.numel());
           // Generating output vectors with estimated lengths
           // The extra length (+1) is to store the actual lengths
           NDArray olens (dim_vector (icen+1,1));
