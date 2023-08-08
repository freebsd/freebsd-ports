--- aten/src/ATen/cpu/vec/vec512/vec512_bfloat16.h.orig	2023-05-07 17:07:36 UTC
+++ aten/src/ATen/cpu/vec/vec512/vec512_bfloat16.h
@@ -283,7 +283,7 @@ template <> class Vectorized<BFloat16> { (public)
   }
   #pragma clang diagnostic push
   #pragma clang diagnostic ignored "-Wignored-qualifiers"
-  Vectorized<BFloat16> map(const __m512 (*const vop)(__m512)) const {
+  Vectorized<BFloat16> map(__m512 (*const vop)(__m512)) const {
     __m512 lo, hi;
     cvtbf16_fp32(values, lo, hi);
     const auto o1 = vop(lo);
