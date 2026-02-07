--- src/library/blas/xgemm.cc.orig	2016-01-05 17:04:55 UTC
+++ src/library/blas/xgemm.cc
@@ -75,19 +75,19 @@ bool isZero(Precision value);
 template<>
 bool isZero<float>( float value ) {
   return value == 0;
-};
+}
 template<>
 bool isZero<double>( double value ) {
   return value == 0;
-};
+}
 template<>
 bool isZero<FloatComplex>( FloatComplex value ) {
   return CREAL(value) == 0 && CIMAG(value) == 0;
-};
+}
 template<>
 bool isZero<DoubleComplex>( DoubleComplex value ) {
   return CREAL(value) == 0 && CIMAG(value) == 0;
-};
+}
 
 static char *getKernelName(cl_kernel clKernel)
 {
