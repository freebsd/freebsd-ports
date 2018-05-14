--- lazy.cc.orig	2015-08-14 22:25:52 UTC
+++ lazy.cc
@@ -35,7 +35,7 @@ Performs simple nonlinear noise reductio
 @item X\n\
 Must be realvector. If it is a row vector then the output will be row vectors as well.\n\
 @item m\n\
-Embedding dimension. Must be postive integer.\n\
+Embedding dimension. Must be positive integer.\n\
 @item rv\n\
 If @var{rv} > 0 then it is equal to the absolute radius of the neighbourhoods. If @var{rv} < 0 then its opposite (-@var{rv}) is equal to the fraction of standard deviation used. It cannot be equal 0.\n\
 @item imax\n\
@@ -71,12 +71,19 @@ Uses TISEAN package lazy\n\
 // In order to avoid clobbered warnings transposed is initialized globally.
 bool transposed;
 
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
   F77_FUNC (ts_lazy, TS_LAZY)
-            (const int& m, const double& rv,
-             const int& imax, const int& lines_read,
+            (const F77_INT& m, const double& rv,
+             const F77_INT& imax, const F77_INT& lines_read,
              double* in_out1, double* in_out2);
 }
 
@@ -100,12 +107,12 @@ DEFUN_DLD (lazy, args, nargout, HELPTEXT
     {
     // Assigning inputs
       Matrix in_out1 = args(0).matrix_value();
-      int m          = args(1).int_value();
+      F77_INT m      = TO_F77_INT (args(1).int_value());
       double rv      = args(2).double_value();
-      int imax       = DEFAULT_IMAX;
+      F77_INT imax   = DEFAULT_IMAX;
 
       if (nargin == 4)
-        imax = args(3).int_value();
+        imax = TO_F77_INT (args(3).int_value());
 
 // --- DATA VALIDATION ---
 
@@ -144,7 +151,7 @@ DEFUN_DLD (lazy, args, nargout, HELPTEXT
               in_out1    = in_out1.transpose();
             }
 
-          int lines_read = in_out1.numel();
+          F77_INT lines_read = TO_F77_INT (in_out1.numel());
           NDArray in_out2 (Matrix (lines_read, 1));
 
           F77_XFCN (ts_lazy, TS_LAZY,
