--- avidemux_plugins/ADM_videoEncoder/x264/ADM_x264.h.orig	2016-01-29 08:47:25 UTC
+++ avidemux_plugins/ADM_videoEncoder/x264/ADM_x264.h
@@ -108,7 +108,7 @@ extern "C"
 	1.0,	/* float rate_tolerance; */ \
 	0,	/* uint32_t vbv_max_bitrate; */ \
 	0,	/* uint32_t vbv_buffer_size; */ \
-	0.9,	/* uint32_t vbv_buffer_init; */ \
+	1,	/* uint32_t vbv_buffer_init; */ \
 	1.4,	/* float ip_factor; */ \
 	1.3,	/* float pb_factor; */ \
 	1,	/* uint32_t aq_mode; */ \
