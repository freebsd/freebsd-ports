--- include/Lcomplex.h.orig	2012-08-08 21:21:55 UTC
+++ include/Lcomplex.h
@@ -34,6 +34,7 @@
 // Initially implemented by Ulrich Drepper <drepper@cygnus.com>
 // Improved by Gabriel Dos Reis <dosreis@cmla.ens-cachan.fr>
 //
+// Patches borrowed from SageMath.
 
 /** @file complex
  *  This is a Standard C++ Library header.  You should @c #include this header
@@ -45,8 +46,6 @@
 
 #pragma GCC system_header
 
-#include <bits/c++config.h>
-
 //no longer include:
 //#include <bits/cpp_type_traits.h>  only thing used was is_floating... 
 //gcc 4.0 cpp_type_traits.h is not compatible with gcc 3.3. 
@@ -135,7 +134,7 @@ namespace std
       template<typename _Up>
         complex<_Tp>& operator/=(const complex<_Up>&);
 
-      friend reset(complex<_Tp>& C) {
+      friend void reset(complex<_Tp>& C) {
 	      reset(C._M_real);
 	      reset(C._M_imag);
       }
