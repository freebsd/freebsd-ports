--- include/lapacke.h.orig	2010-12-03 20:56:19.000000000 +0900
+++ include/lapacke.h	2010-12-03 20:56:59.000000000 +0900
@@ -84,7 +84,7 @@
 #endif
 
 #ifndef lapack_complex_float_imag
-#define lapack_complex_float_imag(z)       (imag(z))
+#define lapack_complex_float_imag(z)       (cimag(z))
 #endif
 
 lapack_complex_float lapack_make_complex_float( float re, float im );
@@ -100,7 +100,7 @@
 #endif
 
 #ifndef lapack_complex_double_imag
-#define lapack_complex_double_imag(z)       (imag(z))
+#define lapack_complex_double_imag(z)       (cimag(z))
 #endif
 
 lapack_complex_double lapack_make_complex_double( double re, double im );
