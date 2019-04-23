--- src/base/low/cl_low_mul.cc.orig	2011-04-08 21:06:30 UTC
+++ src/base/low/cl_low_mul.cc
@@ -50,11 +50,11 @@ uint64 mulu32_w (uint32 arg1, uint32 arg2)
 
 
 #ifdef NEED_VAR_mulu64_high
-uint64 mulu64_high;
+extern "C" uint64 mulu64_high;
 #endif
 
 #ifdef NEED_FUNCTION_mulu64_
-uint64 mulu64_high;
+extern "C" uint64 mulu64_high = 0;
 namespace cln {
 extern "C" uint64 mulu64_ (uint64 x, uint64 y);
 uint64 mulu64_ (uint64 x, uint64 y)
