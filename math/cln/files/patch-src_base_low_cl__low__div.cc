--- src/base/low/cl_low_div.cc.orig	2011-04-08 21:07:28 UTC
+++ src/base/low/cl_low_div.cc
@@ -207,7 +207,7 @@ uint32 divu_6432_3232_(uint32 xhi, uint32 xlo, uint32 
 #endif
 
 #ifdef NEED_VAR_divu_64_rest
-uint64 divu_64_rest;
+extern "C" uint64 divu_64_rest = 0;
 #endif
 
 #ifdef NEED_FUNCTION_divu_6464_6464_
