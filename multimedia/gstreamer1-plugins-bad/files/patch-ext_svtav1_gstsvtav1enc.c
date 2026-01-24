https://gitlab.freedesktop.org/gstreamer/gstreamer/-/commit/a6cdd54b4d8f

--- ext/svtav1/gstsvtav1enc.c.orig	2025-12-25 14:44:26 UTC
+++ ext/svtav1/gstsvtav1enc.c
@@ -80,7 +80,9 @@ typedef struct _GstSvtAv1Enc
 #else
   gint logical_processors;
 #endif
+#if !SVT_AV1_CHECK_VERSION(4, 0, 0)
   gint target_socket;
+#endif
   gchar *parameters_string;
 
   EbBufferHeaderType *input_buf;
@@ -132,7 +134,7 @@ enum
   PROP_INTRA_PERIOD_LENGTH,
   PROP_INTRA_REFRESH_TYPE,
   PROP_LOGICAL_PROCESSORS,      /// DEPRECATED: should be removed once the minimum version is 3.0.0
-  PROP_TARGET_SOCKET,
+  PROP_TARGET_SOCKET,           /// DEPRECATED: should be removed once the minimum version is 4.0.0
   PROP_PARAMETERS_STRING,
   PROP_LEVEL_OF_PARALLELISM,
 };
@@ -149,7 +151,7 @@ enum
 #define PROP_INTRA_REFRESH_TYPE_DEFAULT SVT_AV1_KF_REFRESH
 #define PROP_LEVEL_OF_PARALLELISM_DEFAULT 0
 #define PROP_LOGICAL_PROCESSORS_DEFAULT 0       /// DEPRECATED: should be removed once the minimum version is 3.0.0
-#define PROP_TARGET_SOCKET_DEFAULT -1
+#define PROP_TARGET_SOCKET_DEFAULT -1   /// DEPRECATED: should be removed once the minimum version is 4.0.0
 #define PROP_PARAMETERS_STRING_DEFAULT NULL
 
 #if G_BYTE_ORDER == G_LITTLE_ENDIAN
@@ -339,10 +341,12 @@ gst_svtav1enc_class_init (GstSvtAv1EncClass * klass)
           G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS | G_PARAM_DEPRECATED));
 
   g_object_class_install_property (gobject_class,
-      PROP_TARGET_SOCKET,
-      g_param_spec_int ("target-socket",
-          "Target socket",
+      PROP_TARGET_SOCKET, g_param_spec_int ("target-socket", "Target socket",
+#if SVT_AV1_CHECK_VERSION(4, 0, 0)
+          "Deprecated. This property is ignored in SVT-AV1 4.0.0 and later.",
+#else
           "Target CPU socket to run on. -1: all available",
+#endif
           -1,
           15,
           PROP_TARGET_SOCKET_DEFAULT,
@@ -378,7 +382,9 @@ gst_svtav1enc_init (GstSvtAv1Enc * svtav1enc)
 #else
   svtav1enc->logical_processors = PROP_LOGICAL_PROCESSORS_DEFAULT;
 #endif
+#if !SVT_AV1_CHECK_VERSION(4, 0, 0)
   svtav1enc->target_socket = PROP_TARGET_SOCKET_DEFAULT;
+#endif
   svtav1enc->parameters_string = PROP_PARAMETERS_STRING_DEFAULT;
 }
 
@@ -439,7 +445,9 @@ gst_svtav1enc_set_property (GObject * object, guint pr
 #endif
       break;
     case PROP_TARGET_SOCKET:
+#if !SVT_AV1_CHECK_VERSION(4, 0, 0)
       svtav1enc->target_socket = g_value_get_int (value);
+#endif
       break;
     case PROP_PARAMETERS_STRING:{
       g_free (svtav1enc->parameters_string);
@@ -500,7 +508,9 @@ gst_svtav1enc_get_property (GObject * object, guint pr
 #endif
       break;
     case PROP_TARGET_SOCKET:
+#if !SVT_AV1_CHECK_VERSION(4, 0, 0)
       g_value_set_int (value, svtav1enc->target_socket);
+#endif
       break;
     case PROP_PARAMETERS_STRING:
       g_value_set_string (value, svtav1enc->parameters_string);
@@ -586,7 +596,11 @@ gst_svtav1enc_configure_svt (GstSvtAv1Enc * svtav1enc)
     GST_DEBUG_OBJECT (svtav1enc, "Enabling CQP mode (qp %u)", svtav1enc->cqp);
     svtav1enc->svt_config->qp = svtav1enc->cqp;
     svtav1enc->svt_config->rate_control_mode = SVT_AV1_RC_MODE_CQP_OR_CRF;
+#if SVT_AV1_CHECK_VERSION(4, 0, 0)
+    svtav1enc->svt_config->aq_mode = 0;
+#else
     svtav1enc->svt_config->enable_adaptive_quantization = FALSE;
+#endif
     svtav1enc->svt_config->force_key_frames = TRUE;
   } else {
     GST_DEBUG_OBJECT (svtav1enc, "Using default rate control settings");
@@ -598,7 +612,9 @@ gst_svtav1enc_configure_svt (GstSvtAv1Enc * svtav1enc)
 #else
   svtav1enc->svt_config->logical_processors = svtav1enc->logical_processors;
 #endif
+#if !SVT_AV1_CHECK_VERSION(4, 0, 0)
   svtav1enc->svt_config->target_socket = svtav1enc->target_socket;
+#endif
   gst_svtav1enc_parse_parameters_string (svtav1enc);
 
   /* set properties out of GstVideoInfo */
