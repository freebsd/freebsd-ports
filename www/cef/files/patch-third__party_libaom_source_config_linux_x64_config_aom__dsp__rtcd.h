--- third_party/libaom/source/config/linux/x64/config/aom_dsp_rtcd.h.orig	2026-08-31 10:59:09 UTC
+++ third_party/libaom/source/config/linux/x64/config/aom_dsp_rtcd.h
@@ -59,8 +59,6 @@ void aom_blend_a64_vmask_c(uint8_t *dst, uint32_t dst_
 void aom_blend_a64_vmask_sse4_1(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0, uint32_t src0_stride, const uint8_t *src1, uint32_t src1_stride, const uint8_t *mask, int w, int h);
 RTCD_EXTERN void (*aom_blend_a64_vmask)(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0, uint32_t src0_stride, const uint8_t *src1, uint32_t src1_stride, const uint8_t *mask, int w, int h);
 
-int64_t aom_calc_variance_stat_c(const uint8_t *src, int stride, int bw, int bh);
-int64_t aom_calc_variance_stat_avx2(const uint8_t *src, int stride, int bw, int bh);
 RTCD_EXTERN int64_t (*aom_calc_variance_stat)(const uint8_t *src, int stride, int bw, int bh);
 
 void aom_comp_avg_pred_c(uint8_t *comp_pred, const uint8_t *pred, int width, int height, const uint8_t *ref, int ref_stride);
@@ -445,8 +443,6 @@ void aom_hadamard_lp_8x8_dual_sse2(const int16_t *src_
 void aom_hadamard_lp_8x8_dual_avx2(const int16_t *src_diff, ptrdiff_t src_stride, int16_t *coeff);
 RTCD_EXTERN void (*aom_hadamard_lp_8x8_dual)(const int16_t *src_diff, ptrdiff_t src_stride, int16_t *coeff);
 
-int64_t aom_highbd_calc_variance_stat_c(const uint16_t *src, int stride, int bw, int bh);
-int64_t aom_highbd_calc_variance_stat_avx2(const uint16_t *src, int stride, int bw, int bh);
 RTCD_EXTERN int64_t (*aom_highbd_calc_variance_stat)(const uint16_t *src, int stride, int bw, int bh);
 
 void aom_ifft16x16_float_c(const float *input, float *temp, float *output);
@@ -1717,8 +1713,6 @@ static void setup_rtcd_internal(void)
     if (flags & HAS_AVX2) aom_blend_a64_mask = aom_blend_a64_mask_avx2;
     aom_blend_a64_vmask = aom_blend_a64_vmask_c;
     if (flags & HAS_SSE4_1) aom_blend_a64_vmask = aom_blend_a64_vmask_sse4_1;
-    aom_calc_variance_stat = aom_calc_variance_stat_c;
-    if (flags & HAS_AVX2) aom_calc_variance_stat = aom_calc_variance_stat_avx2;
     aom_comp_avg_pred = aom_comp_avg_pred_c;
     if (flags & HAS_AVX2) aom_comp_avg_pred = aom_comp_avg_pred_avx2;
     aom_comp_mask_pred = aom_comp_mask_pred_c;
@@ -1794,8 +1788,6 @@ static void setup_rtcd_internal(void)
     if (flags & HAS_AVX2) aom_hadamard_lp_16x16 = aom_hadamard_lp_16x16_avx2;
     aom_hadamard_lp_8x8_dual = aom_hadamard_lp_8x8_dual_sse2;
     if (flags & HAS_AVX2) aom_hadamard_lp_8x8_dual = aom_hadamard_lp_8x8_dual_avx2;
-    aom_highbd_calc_variance_stat = aom_highbd_calc_variance_stat_c;
-    if (flags & HAS_AVX2) aom_highbd_calc_variance_stat = aom_highbd_calc_variance_stat_avx2;
     aom_ifft16x16_float = aom_ifft16x16_float_sse2;
     if (flags & HAS_AVX2) aom_ifft16x16_float = aom_ifft16x16_float_avx2;
     aom_ifft32x32_float = aom_ifft32x32_float_sse2;
