--- src/base/low/cl_low_div.cc.orig	2011-04-08 21:07:28 UTC
+++ src/base/low/cl_low_div.cc
@@ -10,11 +10,11 @@
 // Implementation.
 
 #ifdef NEED_VAR_divu_16_rest
-uint16 divu_16_rest;
+extern "C" uint16 divu_16_rest;
 #endif
 
 #ifdef NEED_FUNCTION_divu_3216_1616_
-uint16 divu_16_rest;
+extern "C" uint16 divu_16_rest = 0;
 namespace cln {
 #if 1
 // Most processors have a good 32 by 32 bit division, use that.
@@ -101,11 +101,11 @@ uint32 divu_3232_3232_(uint32 x, uint32 y)
 #endif
 
 #ifdef NEED_VAR_divu_32_rest
-uint32 divu_32_rest;
+extern "C" uint32 divu_32_rest;
 #endif
 
 #ifdef NEED_FUNCTION_divu_6432_3232_
-uint32 divu_32_rest;
+extern "C" uint32 divu_32_rest = 0;
 namespace cln {
 uint32 divu_6432_3232_(uint32 xhi, uint32 xlo, uint32 y)
 // Methode:
@@ -207,7 +207,7 @@ uint32 divu_6432_3232_(uint32 xhi, uint32 xlo, uint32 
 #endif
 
 #ifdef NEED_VAR_divu_64_rest
-uint64 divu_64_rest;
+extern "C" uint64 divu_64_rest = 0;
 #endif
 
 #ifdef NEED_FUNCTION_divu_6464_6464_
