--- aten/src/ATen/cpu/vec/vec256/vec256_bfloat16.h.orig	2024-03-27 22:28:51 UTC
+++ aten/src/ATen/cpu/vec/vec256/vec256_bfloat16.h
@@ -265,7 +265,7 @@ static_assert( (public)
     }
     return b;
   }
-  Vectorized<T> map(const __m256 (*const vop)(__m256)) const {
+  Vectorized<T> map(__m256 (*const vop)(__m256)) const {
     __m256 lo, hi;
     cvt_to_fp32<T>(values, lo, hi);
     const auto o1 = vop(lo);
