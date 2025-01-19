--- src/kernel/integer/random-integer.h.orig	2021-12-14 10:00:03 UTC
+++ src/kernel/integer/random-integer.h
@@ -11,10 +11,12 @@
 
 #include "gmp++/gmp++.h"
 
+#if __cpp_lib_bool_constant < 201505L
 namespace std {
     template <bool B>
     using bool_constant = integral_constant<bool, B>;
 }
+#endif
 
 namespace Givaro
 {
@@ -91,7 +93,6 @@ namespace Givaro
             if (this != &R) {
                 _bits = R._bits;
                 _integer = R._integer;
-                const_cast<Integer_Domain&>(_ring)=R._ring;
             }
             return *this;
         }
