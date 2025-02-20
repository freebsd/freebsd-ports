https://gitlab.com/AOMediaCodec/SVT-AV1/-/issues/2252

--- gstsvtav1enc.c.orig	2025-02-20 14:51:11 UTC
+++ gstsvtav1enc.c
@@ -535,10 +535,8 @@ static gboolean gst_svtav1enc_configure_svt(GstSvtAv1E
         svtav1enc->svt_config->mastering_display.white_point.y = master_display_info.white_point.y;
         svtav1enc->svt_config->mastering_display.max_luma      = master_display_info.max_display_mastering_luminance;
         svtav1enc->svt_config->mastering_display.min_luma      = master_display_info.min_display_mastering_luminance;
-        svtav1enc->svt_config->high_dynamic_range_input        = true;
     } else {
         memset(&svtav1enc->svt_config->mastering_display, 0, sizeof(svtav1enc->svt_config->mastering_display));
-        svtav1enc->svt_config->high_dynamic_range_input = false;
     }
 
     GstVideoContentLightLevel content_light_level;
