--- third_party/libaom/source/config/linux/x64/config/av1_rtcd.h.orig	2026-11-19 12:25:27 UTC
+++ third_party/libaom/source/config/linux/x64/config/av1_rtcd.h
@@ -129,8 +129,6 @@ void av1_build_compound_diffwtd_mask_d16_avx2(uint8_t 
 RTCD_EXTERN void (*av1_build_compound_diffwtd_mask_d16)(uint8_t *mask, DIFFWTD_MASK_TYPE mask_type, const CONV_BUF_TYPE *src0, int src0_stride, const CONV_BUF_TYPE *src1, int src1_stride, int h, int w, ConvolveParams *conv_params, int bd);
 
 void av1_calc_centroids_dim1_c(const int16_t *data, int16_t *centroids, const uint8_t *indices, int n, int k);
-void av1_calc_centroids_dim1_sse2(const int16_t *data, int16_t *centroids, const uint8_t *indices, int n, int k);
-void av1_calc_centroids_dim1_avx2(const int16_t *data, int16_t *centroids, const uint8_t *indices, int n, int k);
 RTCD_EXTERN void (*av1_calc_centroids_dim1)(const int16_t *data, int16_t *centroids, const uint8_t *indices, int n, int k);
 
 void av1_calc_centroids_dim2_c(const int16_t *data, int16_t *centroids, const uint8_t *indices, int n, int k);
@@ -535,8 +533,6 @@ static void setup_rtcd_internal(void)
     av1_build_compound_diffwtd_mask_d16 = av1_build_compound_diffwtd_mask_d16_c;
     if (flags & HAS_SSE4_1) av1_build_compound_diffwtd_mask_d16 = av1_build_compound_diffwtd_mask_d16_sse4_1;
     if (flags & HAS_AVX2) av1_build_compound_diffwtd_mask_d16 = av1_build_compound_diffwtd_mask_d16_avx2;
-    av1_calc_centroids_dim1 = av1_calc_centroids_dim1_sse2;
-    if (flags & HAS_AVX2) av1_calc_centroids_dim1 = av1_calc_centroids_dim1_avx2;
     av1_calc_indices_dim1 = av1_calc_indices_dim1_sse2;
     if (flags & HAS_AVX2) av1_calc_indices_dim1 = av1_calc_indices_dim1_avx2;
     av1_calc_indices_dim2 = av1_calc_indices_dim2_sse2;
