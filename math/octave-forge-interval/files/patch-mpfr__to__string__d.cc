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
@@ -219,7 +219,7 @@ DEFUN_DLD (mpfr_to_string_d, args, nargo
               
               // shift mantissa by 32 bits to format the first part
               // sprintf (... "%x" ...) requires an unsigned 4-byte int 
-              mantissa *= std::pow (2.0, sizeof (uint32_t) * 8);
+              mantissa *= uint64_t (1) << (sizeof (uint32_t) * 8);
               uint32_t first_part = static_cast <uint32_t> (mantissa);
               
               // remove first mantissa part
@@ -227,7 +227,7 @@ DEFUN_DLD (mpfr_to_string_d, args, nargo
               
               // shift mantissa by remaining 20 bits such that
               // it is an integer
-              mantissa *= std::pow (2.0,
+              mantissa *= uint64_t (1) << (
                                     std::numeric_limits
                                       <double>::digits - 1 - 32);
               uint32_t second_part = static_cast <uint32_t> (mantissa);
