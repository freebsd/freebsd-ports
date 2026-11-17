--- csrc/cpu/cpu_types_x86.hpp.orig	2026-11-02 08:07:02 UTC
+++ csrc/cpu/cpu_types_x86.hpp
@@ -586,7 +586,12 @@ struct FP32Vec16 : public Vec<FP32Vec16> {
             _mm512_bslli_epi128(_mm512_cvtepu16_epi32(v.reg), 2))) {}
 
   explicit FP32Vec16(const BF16Vec32& v, int upper) {
-    __m256i v_half_i = _mm512_extracti32x8_epi32(v.reg, upper);
+    __m256i v_half_i;
+    if (upper) {
+      v_half_i = _mm512_extracti32x8_epi32(v.reg, 1);
+    } else {
+      v_half_i = _mm512_castsi512_si256(v.reg);
+    }
     reg = _mm512_cvtph_ps(v_half_i);
   }
 
