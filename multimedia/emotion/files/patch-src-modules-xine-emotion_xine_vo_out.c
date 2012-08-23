--- src/modules/xine/emotion_xine_vo_out.c.orig
+++ src/modules/xine/emotion_xine_vo_out.c
@@ -119,8 +119,13 @@ _emotion_class_init(xine_t *xine, void *
    cl = (Emotion_Class *) malloc(sizeof(Emotion_Class));
    if (!cl) return NULL;
    cl->driver_class.open_plugin     = _emotion_open;
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2) 
    cl->driver_class.get_identifier  = _emotion_class_identifier_get;
    cl->driver_class.get_description = _emotion_class_description_get;
+#else
+   cl->driver_class.identifier      = _emotion_class_identifier_get(NULL);
+   cl->driver_class.description     = _emotion_class_description_get(NULL);
+#endif
    cl->driver_class.dispose         = _emotion_class_dispose;
    cl->config                       = xine->config;
    cl->xine                         = xine;
