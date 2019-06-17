https://gitlab.freedesktop.org/gstreamer/gst-plugins-bad/commit/d2f6facbfb89

gstopenh264enc.cpp:745:14: error: no member named 'bEnableSpsPpsIdAddition' in 'TagEncParamExt'
  enc_params.bEnableSpsPpsIdAddition = 0;
  ~~~~~~~~~~ ^

--- ext/openh264/gstopenh264enc.cpp.orig	2018-03-23 20:45:15 UTC
+++ ext/openh264/gstopenh264enc.cpp
@@ -739,7 +739,7 @@ gst_openh264enc_set_format (GstVideoEncoder * encoder,
   enc_params.bEnableSceneChangeDetect = openh264enc->scene_change_detection;
   enc_params.bEnableFrameSkip = openh264enc->enable_frame_skip;
   enc_params.bEnableLongTermReference = 0;
-#if OPENH264_MINOR >= 4
+#if (OPENH264_MAJOR > 1 || (OPENH264_MAJOR == 1 && OPENH264_MINOR >= 4))
   enc_params.eSpsPpsIdStrategy = CONSTANT_ID;
 #else
   enc_params.bEnableSpsPpsIdAddition = 0;
