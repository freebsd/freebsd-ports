--- third_party/libaom/source/config/linux/arm64-cpu-detect/config/av1_rtcd.h.orig	2026-11-19 12:25:27 UTC
+++ third_party/libaom/source/config/linux/arm64-cpu-detect/config/av1_rtcd.h
@@ -201,8 +201,10 @@ RTCD_EXTERN void (*av1_dist_wtd_convolve_x)(const uint
 
 void av1_dist_wtd_convolve_y_c(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams *filter_params_y, const int subpel_y_qn, ConvolveParams *conv_params);
 void av1_dist_wtd_convolve_y_neon(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams *filter_params_y, const int subpel_y_qn, ConvolveParams *conv_params);
+#if (VERSION_PACKED > 199937)
 void av1_dist_wtd_convolve_y_neon_dotprod(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams *filter_params_y, const int subpel_y_qn, ConvolveParams *conv_params);
 void av1_dist_wtd_convolve_y_neon_i8mm(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams *filter_params_y, const int subpel_y_qn, ConvolveParams *conv_params);
+#endif
 RTCD_EXTERN void (*av1_dist_wtd_convolve_y)(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams *filter_params_y, const int subpel_y_qn, ConvolveParams *conv_params);
 
 void av1_dr_prediction_z1_c(uint8_t *dst, ptrdiff_t stride, int bw, int bh, const uint8_t *above, const uint8_t *left, int upsample_above, int dx, int dy);
@@ -541,8 +543,10 @@ static void setup_rtcd_internal(void)
     if (flags & HAS_NEON_DOTPROD) av1_dist_wtd_convolve_x = av1_dist_wtd_convolve_x_neon_dotprod;
     if (flags & HAS_NEON_I8MM) av1_dist_wtd_convolve_x = av1_dist_wtd_convolve_x_neon_i8mm;
     av1_dist_wtd_convolve_y = av1_dist_wtd_convolve_y_neon;
+#if (VERSION_PACKED > 199937)
     if (flags & HAS_NEON_DOTPROD) av1_dist_wtd_convolve_y = av1_dist_wtd_convolve_y_neon_dotprod;
     if (flags & HAS_NEON_I8MM) av1_dist_wtd_convolve_y = av1_dist_wtd_convolve_y_neon_i8mm;
+#endif
     av1_filter_intra_predictor = av1_filter_intra_predictor_neon;
     if (flags & HAS_NEON_I8MM) av1_filter_intra_predictor = av1_filter_intra_predictor_neon_i8mm;
     av1_get_crc32c_value = av1_get_crc32c_value_c;
