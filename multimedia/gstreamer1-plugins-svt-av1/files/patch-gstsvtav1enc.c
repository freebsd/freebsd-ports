https://gitlab.com/AOMediaCodec/SVT-AV1/-/issues/2252
https://gitlab.freedesktop.org/gstreamer/gstreamer/-/commit/a6cdd54b4d8f

--- gstsvtav1enc.c.orig	2025-02-20 14:51:11 UTC
+++ gstsvtav1enc.c
@@ -277,7 +277,7 @@ static void gst_svtav1enc_class_init(GstSvtAv1EncClass
                                     PROP_TARGET_SOCKET,
                                     g_param_spec_int("target-socket",
                                                      "Target socket",
-                                                     "Target CPU socket to run on. -1: all available",
+                                                     "Deprecated. This property is ignored in SVT-AV1 4.0.0 and later.",
                                                      -1,
                                                      15,
                                                      PROP_TARGET_SOCKET_DEFAULT,
@@ -434,7 +434,7 @@ static gboolean gst_svtav1enc_configure_svt(GstSvtAv1E
         GST_DEBUG_OBJECT(svtav1enc, "Enabling CQP mode (qp %u)", svtav1enc->cqp);
         svtav1enc->svt_config->qp                           = svtav1enc->cqp;
         svtav1enc->svt_config->rate_control_mode            = SVT_AV1_RC_MODE_CQP_OR_CRF;
-        svtav1enc->svt_config->enable_adaptive_quantization = false;
+        svtav1enc->svt_config->aq_mode                      = 0;
         svtav1enc->svt_config->force_key_frames             = true;
     } else {
         GST_DEBUG_OBJECT(svtav1enc, "Using default rate control settings");
@@ -442,7 +442,6 @@ static gboolean gst_svtav1enc_configure_svt(GstSvtAv1E
     svtav1enc->svt_config->intra_period_length  = svtav1enc->intra_period_length;
     svtav1enc->svt_config->intra_refresh_type   = svtav1enc->intra_refresh_type;
     svtav1enc->svt_config->level_of_parallelism = svtav1enc->level_of_parallelism;
-    svtav1enc->svt_config->target_socket        = svtav1enc->target_socket;
     gst_svtav1enc_parse_parameters_string(svtav1enc);
 
     /* set properties out of GstVideoInfo */
@@ -535,10 +534,8 @@ static gboolean gst_svtav1enc_configure_svt(GstSvtAv1E
         svtav1enc->svt_config->mastering_display.white_point.y = master_display_info.white_point.y;
         svtav1enc->svt_config->mastering_display.max_luma      = master_display_info.max_display_mastering_luminance;
         svtav1enc->svt_config->mastering_display.min_luma      = master_display_info.min_display_mastering_luminance;
-        svtav1enc->svt_config->high_dynamic_range_input        = true;
     } else {
         memset(&svtav1enc->svt_config->mastering_display, 0, sizeof(svtav1enc->svt_config->mastering_display));
-        svtav1enc->svt_config->high_dynamic_range_input = false;
     }
 
     GstVideoContentLightLevel content_light_level;
