--- ext/qt/gstqsgtexture.cc.orig	2021-08-02 23:41:35 UTC
+++ ext/qt/gstqsgtexture.cc
@@ -39,7 +39,7 @@ GstQSGTexture::GstQSGTexture ()
 
   initializeOpenGLFunctions();
 
-  if (g_once_init_enter (&_debug)) {
+  if (g_once_init_enter ((unsigned long *)&_debug)) {
     GST_DEBUG_CATEGORY_INIT (GST_CAT_DEFAULT, "qtqsgtexture", 0,
         "Qt Scenegraph Texture");
     g_once_init_leave (&_debug, 1);
