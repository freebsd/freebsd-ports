--- mpfr_to_string_d.cc.orig	2016-11-24 18:19:39 UTC
+++ mpfr_to_string_d.cc
@@ -201,10 +201,10 @@ DEFUN_DLD (mpfr_to_string_d, args, nargo
               // Make subnormal numbers use the exponent -1022
               if (exponent < std::numeric_limits <double>::min_exponent)
                 {
-                  mantissa /= std::pow (2.0, 
+                  mantissa /= std::pow (2.0, (int)(
                                         std::numeric_limits
                                           <double>::min_exponent - 1
-                                        - exponent);
+                                        - exponent));
                   exponent = std::numeric_limits <double>::min_exponent - 1;
                 }
             
