--- third_party/libaom/source/config/linux/x64/config/aom_dsp_rtcd.h.orig	2026-09-25 15:26:43 UTC
+++ third_party/libaom/source/config/linux/x64/config/aom_dsp_rtcd.h
@@ -59,8 +59,6 @@ void aom_blend_a64_vmask_c(uint8_t *dst, uint32_t dst_
 void aom_blend_a64_vmask_sse4_1(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0, uint32_t src0_stride, const uint8_t *src1, uint32_t src1_stride, const uint8_t *mask, int w, int h);
 RTCD_EXTERN void (*aom_blend_a64_vmask)(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0, uint32_t src0_stride, const uint8_t *src1, uint32_t src1_stride, const uint8_t *mask, int w, int h);
 
-int64_t aom_calc_variance_stat_c(const uint8_t *src, int stride, int bw, int bh);
-int64_t aom_calc_variance_stat_avx2(const uint8_t *src, int stride, int bw, int bh);
 RTCD_EXTERN int64_t (*aom_calc_variance_stat)(const uint8_t *src, int stride, int bw, int bh);
 
 void aom_comp_avg_pred_c(uint8_t *comp_pred, const uint8_t *pred, int width, int height, const uint8_t *ref, int ref_stride);
@@ -1713,8 +1711,6 @@ static void setup_rtcd_internal(void)
     if (flags & HAS_AVX2) aom_blend_a64_mask = aom_blend_a64_mask_avx2;
     aom_blend_a64_vmask = aom_blend_a64_vmask_c;
     if (flags & HAS_SSE4_1) aom_blend_a64_vmask = aom_blend_a64_vmask_sse4_1;
-    aom_calc_variance_stat = aom_calc_variance_stat_c;
-    if (flags & HAS_AVX2) aom_calc_variance_stat = aom_calc_variance_stat_avx2;
     aom_comp_avg_pred = aom_comp_avg_pred_c;
     if (flags & HAS_AVX2) aom_comp_avg_pred = aom_comp_avg_pred_avx2;
     aom_comp_mask_pred = aom_comp_mask_pred_c;
