--- third_party/webrtc/modules/video_coding/codecs/av1/libaom_av1_encoder.cc.orig	2026-03-13 06:02:14 UTC
+++ third_party/webrtc/modules/video_coding/codecs/av1/libaom_av1_encoder.cc
@@ -67,6 +67,10 @@
 #define AOM_EFLAG_CALCULATE_PSNR (1 << 3)
 #endif
 
+#ifndef AOM_EFLAG_FREEZE_INTERNAL_STATE
+#define AOM_EFLAG_FREEZE_INTERNAL_STATE (1 << 2)
+#endif
+
 #if defined(WEBRTC_ENCODER_PSNR_STATS)
 constexpr bool kEnablePsnrStats = true;
 #else
