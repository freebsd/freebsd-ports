--- aten/src/ATen/cpu/vec/vec512/vec512_bfloat16.h.orig	2023-10-12 12:54:40 UTC
+++ aten/src/ATen/cpu/vec/vec512/vec512_bfloat16.h
@@ -345,7 +345,7 @@ static_assert( (public)
   }
   #pragma clang diagnostic push
   #pragma clang diagnostic ignored "-Wignored-qualifiers"
-  Vectorized<T> map(const __m512 (*const vop)(__m512)) const {
+  Vectorized<T> map(__m512 (*const vop)(__m512)) const {
     __m512 lo, hi;
     cvt_to_fp32<T>(values, lo, hi);
     const auto o1 = vop(lo);
