-- Fix type punning in cpu_half2float by using a direct (float) cast instead
-- of casting through void* which is undefined behavior in C++.
--- third_party/gloo/gloo/types.h.orig	2022-08-30 11:33:00 UTC
+++ third_party/gloo/gloo/types.h
@@ -319,8 +319,7 @@ inline float cpu_half2float(float16 h) {
 
   unsigned temp = ((sign << 31) | (exponent << 23) | mantissa);
 
-  void* rp = &temp;
-  return *(float*)rp;
+  return (float)temp;
 }
 
 } // namespace gloo
