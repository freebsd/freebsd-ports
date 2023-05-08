--- aten/src/ATen/cpu/vec/vec256/vec256_bfloat16.h.orig	2023-05-07 16:59:15 UTC
+++ aten/src/ATen/cpu/vec/vec256/vec256_bfloat16.h
@@ -206,7 +206,7 @@ template <> class Vectorized<BFloat16> { (public)
     }
     return b;
   }
-  Vectorized<BFloat16> map(const __m256 (*const vop)(__m256)) const {
+  Vectorized<BFloat16> map(__m256 (*const vop)(__m256)) const {
     __m256 lo, hi;
     cvtbf16_fp32(values, lo, hi);
     const auto o1 = vop(lo);
