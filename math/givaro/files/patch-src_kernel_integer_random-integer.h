--- src/kernel/integer/random-integer.h.orig	2021-12-14 10:00:03 UTC
+++ src/kernel/integer/random-integer.h
@@ -91,7 +91,6 @@ namespace Givaro
             if (this != &R) {
                 _bits = R._bits;
                 _integer = R._integer;
-                const_cast<Integer_Domain&>(_ring)=R._ring;
             }
             return *this;
         }
