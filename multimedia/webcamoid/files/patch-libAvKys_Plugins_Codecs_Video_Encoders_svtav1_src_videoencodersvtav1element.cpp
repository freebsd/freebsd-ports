--- libAvKys/Plugins/Codecs/Video/Encoders/svtav1/src/videoencodersvtav1element.cpp.orig	2025-07-29 01:36:55 UTC
+++ libAvKys/Plugins/Codecs/Video/Encoders/svtav1/src/videoencodersvtav1element.cpp
@@ -344,7 +344,9 @@ bool VideoEncoderSvtAv1ElementPrivate::init()
 
     configs.enc_mode = uint8_t(qBound(0, self->optionValue("speed").toInt(), 9));
     configs.tune = uint8_t(self->optionValue("tuneContent").toUInt());
+#if !SVT_AV1_CHECK_VERSION(2, 0, 0)
     configs.target_socket = -1;
+#endif
 
 #if SVT_AV1_CHECK_VERSION(3, 0, 0)
     configs.level_of_parallelism = QThread::idealThreadCount();
@@ -353,7 +355,9 @@ bool VideoEncoderSvtAv1ElementPrivate::init()
 #endif
 
     configs.rate_control_mode = SVT_AV1_RC_MODE_CBR;
+#if !SVT_AV1_CHECK_VERSION(4, 0, 0)
     configs.pred_structure = SVT_AV1_PRED_LOW_DELAY_B; // Otherwise CBR won't work
+#endif
     configs.target_bit_rate = self->bitrate();
     configs.profile = eqFormat->profile;
     configs.color_primaries = EB_CICP_CP_UNSPECIFIED;
