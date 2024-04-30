--- src/3rdparty/chromium/v8/src/deoptimizer/x64/deoptimizer-x64.cc.orig	2023-07-16 15:47:57 UTC
+++ src/3rdparty/chromium/v8/src/deoptimizer/x64/deoptimizer-x64.cc
@@ -21,7 +21,7 @@ ASSERT_OFFSET(Builtin::kDeoptimizationEntry_Lazy);
 #undef ASSERT_OFFSET
 
 const int Deoptimizer::kEagerDeoptExitSize = 4;
-const int Deoptimizer::kLazyDeoptExitSize = 4;
+const int Deoptimizer::kLazyDeoptExitSize = 8;
 
 Float32 RegisterValues::GetFloatRegister(unsigned n) const {
   return Float32::FromBits(
