--- server/mp4live/video_util_resize.h.orig	2005-03-25 21:40:05.000000000 +0100
+++ server/mp4live/video_util_resize.h	2014-06-15 12:20:58.012489469 +0200
@@ -90,7 +90,7 @@
 
 void CopyYuv(const uint8_t *fY, const uint8_t *fU, const uint8_t *fV,
 	     uint32_t fyStride, uint32_t fuStride, uint32_t fvStride,
-	     uint8_t *tY, uint8_t *tU, uint8_t *fV,
-	     uint32_t tyStride, uint32_t tvStride, uint32_t tvStride,
+	     uint8_t *tY, uint8_t *tU, uint8_t *tV,
+	     uint32_t tyStride, uint32_t tuStride, uint32_t tvStride,
 	     uint32_t w, uint32_t h);
 #endif
