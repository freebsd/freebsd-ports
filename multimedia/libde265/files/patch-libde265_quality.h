--- libde265/quality.h.orig	2025-02-11 06:25:30 UTC
+++ libde265/quality.h
@@ -26,11 +26,11 @@
 #include <libde265/image.h>
 
 
-LIBDE265_API uint32_t SSD(const uint8_t* img, int imgStride,
+uint32_t SSD(const uint8_t* img, int imgStride,
                           const uint8_t* ref, int refStride,
                           int width, int height);
 
-LIBDE265_API uint32_t SAD(const uint8_t* img, int imgStride,
+uint32_t SAD(const uint8_t* img, int imgStride,
                           const uint8_t* ref, int refStride,
                           int width, int height);
 
@@ -41,7 +41,7 @@ LIBDE265_API double PSNR(double mse);
 LIBDE265_API double PSNR(double mse);
 
 
-LIBDE265_API uint32_t compute_distortion_ssd(const de265_image* img1, const de265_image* img2,
+uint32_t compute_distortion_ssd(const de265_image* img1, const de265_image* img2,
                                              int x0, int y0, int log2size, int cIdx);
 
 #endif
