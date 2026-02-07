--- third_party/libaom/source/config/linux/arm64-cpu-detect/config/av1_rtcd.h.orig	2026-01-19 10:05:45 UTC
+++ third_party/libaom/source/config/linux/arm64-cpu-detect/config/av1_rtcd.h
@@ -198,8 +198,6 @@ RTCD_EXTERN void (*av1_dist_wtd_convolve_x)(const uint
 
 void av1_dist_wtd_convolve_y_c(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams *filter_params_y, const int subpel_y_qn, ConvolveParams *conv_params);
 void av1_dist_wtd_convolve_y_neon(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams *filter_params_y, const int subpel_y_qn, ConvolveParams *conv_params);
-void av1_dist_wtd_convolve_y_neon_dotprod(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams *filter_params_y, const int subpel_y_qn, ConvolveParams *conv_params);
-void av1_dist_wtd_convolve_y_neon_i8mm(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams *filter_params_y, const int subpel_y_qn, ConvolveParams *conv_params);
 RTCD_EXTERN void (*av1_dist_wtd_convolve_y)(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const InterpFilterParams *filter_params_y, const int subpel_y_qn, ConvolveParams *conv_params);
 
 void av1_dr_prediction_z1_c(uint8_t *dst, ptrdiff_t stride, int bw, int bh, const uint8_t *above, const uint8_t *left, int upsample_above, int dx, int dy);
@@ -285,9 +283,9 @@ void av1_fwht4x4_c(const int16_t *input, tran_low_t *o
 void av1_fwht4x4_neon(const int16_t *input, tran_low_t *output, int stride);
 #define av1_fwht4x4 av1_fwht4x4_neon
 
-uint32_t av1_get_crc32c_value_c(void *crc_calculator, const uint8_t *p, size_t length);
-uint32_t av1_get_crc32c_value_arm_crc32(void *crc_calculator, const uint8_t *p, size_t length);
-RTCD_EXTERN uint32_t (*av1_get_crc32c_value)(void *crc_calculator, const uint8_t *p, size_t length);
+uint32_t av1_get_crc32c_value_c(void *crc_calculator, uint8_t *p, size_t length);
+uint32_t av1_get_crc32c_value_arm_crc32(void *crc_calculator, uint8_t *p, size_t length);
+RTCD_EXTERN uint32_t (*av1_get_crc32c_value)(void *crc_calculator, uint8_t *p, size_t length);
 
 void av1_get_horver_correlation_full_c(const int16_t *diff, int stride, int w, int h, float *hcorr, float *vcorr);
 void av1_get_horver_correlation_full_neon(const int16_t *diff, int stride, int w, int h, float *hcorr, float *vcorr);
@@ -534,8 +532,6 @@ static void setup_rtcd_internal(void)
     if (flags & HAS_NEON_DOTPROD) av1_dist_wtd_convolve_x = av1_dist_wtd_convolve_x_neon_dotprod;
     if (flags & HAS_NEON_I8MM) av1_dist_wtd_convolve_x = av1_dist_wtd_convolve_x_neon_i8mm;
     av1_dist_wtd_convolve_y = av1_dist_wtd_convolve_y_neon;
-    if (flags & HAS_NEON_DOTPROD) av1_dist_wtd_convolve_y = av1_dist_wtd_convolve_y_neon_dotprod;
-    if (flags & HAS_NEON_I8MM) av1_dist_wtd_convolve_y = av1_dist_wtd_convolve_y_neon_i8mm;
     av1_get_crc32c_value = av1_get_crc32c_value_c;
     if (flags & HAS_ARM_CRC32) av1_get_crc32c_value = av1_get_crc32c_value_arm_crc32;
     av1_resize_and_extend_frame = av1_resize_and_extend_frame_neon;
