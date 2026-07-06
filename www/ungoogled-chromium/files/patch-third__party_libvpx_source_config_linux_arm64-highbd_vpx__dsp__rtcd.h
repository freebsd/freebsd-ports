--- third_party/libvpx/source/config/linux/arm64-highbd/vpx_dsp_rtcd.h.orig	2026-06-05 13:45:06 UTC
+++ third_party/libvpx/source/config/linux/arm64-highbd/vpx_dsp_rtcd.h
@@ -2174,32 +2174,26 @@ uint32_t vpx_sub_pixel_avg_variance8x8_neon(const uint
 
 uint32_t vpx_sub_pixel_variance16x16_c(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 uint32_t vpx_sub_pixel_variance16x16_neon(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
-uint32_t vpx_sub_pixel_variance16x16_neon_dotprod(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 RTCD_EXTERN uint32_t (*vpx_sub_pixel_variance16x16)(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 
 uint32_t vpx_sub_pixel_variance16x32_c(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 uint32_t vpx_sub_pixel_variance16x32_neon(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
-uint32_t vpx_sub_pixel_variance16x32_neon_dotprod(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 RTCD_EXTERN uint32_t (*vpx_sub_pixel_variance16x32)(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 
 uint32_t vpx_sub_pixel_variance16x8_c(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 uint32_t vpx_sub_pixel_variance16x8_neon(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
-uint32_t vpx_sub_pixel_variance16x8_neon_dotprod(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 RTCD_EXTERN uint32_t (*vpx_sub_pixel_variance16x8)(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 
 uint32_t vpx_sub_pixel_variance32x16_c(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 uint32_t vpx_sub_pixel_variance32x16_neon(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
-uint32_t vpx_sub_pixel_variance32x16_neon_dotprod(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 RTCD_EXTERN uint32_t (*vpx_sub_pixel_variance32x16)(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 
 uint32_t vpx_sub_pixel_variance32x32_c(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 uint32_t vpx_sub_pixel_variance32x32_neon(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
-uint32_t vpx_sub_pixel_variance32x32_neon_dotprod(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 RTCD_EXTERN uint32_t (*vpx_sub_pixel_variance32x32)(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 
 uint32_t vpx_sub_pixel_variance32x64_c(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 uint32_t vpx_sub_pixel_variance32x64_neon(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
-uint32_t vpx_sub_pixel_variance32x64_neon_dotprod(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 RTCD_EXTERN uint32_t (*vpx_sub_pixel_variance32x64)(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 
 uint32_t vpx_sub_pixel_variance4x4_c(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
@@ -2208,32 +2202,26 @@ uint32_t vpx_sub_pixel_variance4x4_neon(const uint8_t 
 
 uint32_t vpx_sub_pixel_variance4x8_c(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 uint32_t vpx_sub_pixel_variance4x8_neon(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
-uint32_t vpx_sub_pixel_variance4x8_neon_dotprod(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 RTCD_EXTERN uint32_t (*vpx_sub_pixel_variance4x8)(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 
 uint32_t vpx_sub_pixel_variance64x32_c(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 uint32_t vpx_sub_pixel_variance64x32_neon(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
-uint32_t vpx_sub_pixel_variance64x32_neon_dotprod(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 RTCD_EXTERN uint32_t (*vpx_sub_pixel_variance64x32)(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 
 uint32_t vpx_sub_pixel_variance64x64_c(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 uint32_t vpx_sub_pixel_variance64x64_neon(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
-uint32_t vpx_sub_pixel_variance64x64_neon_dotprod(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 RTCD_EXTERN uint32_t (*vpx_sub_pixel_variance64x64)(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 
 uint32_t vpx_sub_pixel_variance8x16_c(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 uint32_t vpx_sub_pixel_variance8x16_neon(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
-uint32_t vpx_sub_pixel_variance8x16_neon_dotprod(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 RTCD_EXTERN uint32_t (*vpx_sub_pixel_variance8x16)(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 
 uint32_t vpx_sub_pixel_variance8x4_c(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 uint32_t vpx_sub_pixel_variance8x4_neon(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
-uint32_t vpx_sub_pixel_variance8x4_neon_dotprod(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 RTCD_EXTERN uint32_t (*vpx_sub_pixel_variance8x4)(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 
 uint32_t vpx_sub_pixel_variance8x8_c(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 uint32_t vpx_sub_pixel_variance8x8_neon(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
-uint32_t vpx_sub_pixel_variance8x8_neon_dotprod(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 RTCD_EXTERN uint32_t (*vpx_sub_pixel_variance8x8)(const uint8_t *src_ptr, int src_stride, int x_offset, int y_offset, const uint8_t *ref_ptr, int ref_stride, uint32_t *sse);
 
 void vpx_subtract_block_c(int rows, int cols, int16_t *diff_ptr, ptrdiff_t diff_stride, const uint8_t *src_ptr, ptrdiff_t src_stride, const uint8_t *pred_ptr, ptrdiff_t pred_stride);
@@ -2601,29 +2589,17 @@ static void setup_rtcd_internal(void)
     vpx_sse = vpx_sse_neon;
     if (flags & HAS_NEON_DOTPROD) vpx_sse = vpx_sse_neon_dotprod;
     vpx_sub_pixel_variance16x16 = vpx_sub_pixel_variance16x16_neon;
-    if (flags & HAS_NEON_DOTPROD) vpx_sub_pixel_variance16x16 = vpx_sub_pixel_variance16x16_neon_dotprod;
     vpx_sub_pixel_variance16x32 = vpx_sub_pixel_variance16x32_neon;
-    if (flags & HAS_NEON_DOTPROD) vpx_sub_pixel_variance16x32 = vpx_sub_pixel_variance16x32_neon_dotprod;
     vpx_sub_pixel_variance16x8 = vpx_sub_pixel_variance16x8_neon;
-    if (flags & HAS_NEON_DOTPROD) vpx_sub_pixel_variance16x8 = vpx_sub_pixel_variance16x8_neon_dotprod;
     vpx_sub_pixel_variance32x16 = vpx_sub_pixel_variance32x16_neon;
-    if (flags & HAS_NEON_DOTPROD) vpx_sub_pixel_variance32x16 = vpx_sub_pixel_variance32x16_neon_dotprod;
     vpx_sub_pixel_variance32x32 = vpx_sub_pixel_variance32x32_neon;
-    if (flags & HAS_NEON_DOTPROD) vpx_sub_pixel_variance32x32 = vpx_sub_pixel_variance32x32_neon_dotprod;
     vpx_sub_pixel_variance32x64 = vpx_sub_pixel_variance32x64_neon;
-    if (flags & HAS_NEON_DOTPROD) vpx_sub_pixel_variance32x64 = vpx_sub_pixel_variance32x64_neon_dotprod;
     vpx_sub_pixel_variance4x8 = vpx_sub_pixel_variance4x8_neon;
-    if (flags & HAS_NEON_DOTPROD) vpx_sub_pixel_variance4x8 = vpx_sub_pixel_variance4x8_neon_dotprod;
     vpx_sub_pixel_variance64x32 = vpx_sub_pixel_variance64x32_neon;
-    if (flags & HAS_NEON_DOTPROD) vpx_sub_pixel_variance64x32 = vpx_sub_pixel_variance64x32_neon_dotprod;
     vpx_sub_pixel_variance64x64 = vpx_sub_pixel_variance64x64_neon;
-    if (flags & HAS_NEON_DOTPROD) vpx_sub_pixel_variance64x64 = vpx_sub_pixel_variance64x64_neon_dotprod;
     vpx_sub_pixel_variance8x16 = vpx_sub_pixel_variance8x16_neon;
-    if (flags & HAS_NEON_DOTPROD) vpx_sub_pixel_variance8x16 = vpx_sub_pixel_variance8x16_neon_dotprod;
     vpx_sub_pixel_variance8x4 = vpx_sub_pixel_variance8x4_neon;
-    if (flags & HAS_NEON_DOTPROD) vpx_sub_pixel_variance8x4 = vpx_sub_pixel_variance8x4_neon_dotprod;
     vpx_sub_pixel_variance8x8 = vpx_sub_pixel_variance8x8_neon;
-    if (flags & HAS_NEON_DOTPROD) vpx_sub_pixel_variance8x8 = vpx_sub_pixel_variance8x8_neon_dotprod;
     vpx_sum_squares_2d_i16 = vpx_sum_squares_2d_i16_neon;
     if (flags & HAS_SVE) vpx_sum_squares_2d_i16 = vpx_sum_squares_2d_i16_sve;
     vpx_variance16x16 = vpx_variance16x16_neon;
