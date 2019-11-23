--- src/3rdparty/chromium/media/renderers/paint_canvas_video_renderer.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/media/renderers/paint_canvas_video_renderer.cc
@@ -31,8 +31,7 @@
 
 // Skia internal format depends on a platform. On Android it is ABGR, on others
 // it is ARGB.
-#if SK_B32_SHIFT == 0 && SK_G32_SHIFT == 8 && SK_R32_SHIFT == 16 && \
-    SK_A32_SHIFT == 24
+#if SK_PMCOLOR_BYTE_ORDER(B,G,R,A)
 #define LIBYUV_I420_TO_ARGB libyuv::I420ToARGB
 #define LIBYUV_I422_TO_ARGB libyuv::I422ToARGB
 #define LIBYUV_I444_TO_ARGB libyuv::I444ToARGB
@@ -42,8 +41,7 @@
 #define LIBYUV_I010_TO_ARGB libyuv::I010ToARGB
 #define LIBYUV_H010_TO_ARGB libyuv::H010ToARGB
 #define LIBYUV_NV12_TO_ARGB libyuv::NV12ToARGB
-#elif SK_R32_SHIFT == 0 && SK_G32_SHIFT == 8 && SK_B32_SHIFT == 16 && \
-    SK_A32_SHIFT == 24
+#elif SK_PMCOLOR_BYTE_ORDER(R,G,B,A)
 #define LIBYUV_I420_TO_ARGB libyuv::I420ToABGR
 #define LIBYUV_I422_TO_ARGB libyuv::I422ToABGR
 #define LIBYUV_I444_TO_ARGB libyuv::I444ToABGR
