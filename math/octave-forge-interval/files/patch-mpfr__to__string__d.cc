--- mpfr_to_string_d.cc.orig	2016-11-20 13:47:35 UTC
+++ mpfr_to_string_d.cc
@@ -201,7 +201,7 @@ DEFUN_DLD (mpfr_to_string_d, args, nargo
               // Make subnormal numbers use the exponent -1022
               if (exponent < std::numeric_limits <double>::min_exponent)
                 {
-                  mantissa /= std::pow (2.0, 
+                  mantissa /= uint64_t (1) << (
                                         std::numeric_limits
                                           <double>::min_exponent - 1
                                         - exponent);
