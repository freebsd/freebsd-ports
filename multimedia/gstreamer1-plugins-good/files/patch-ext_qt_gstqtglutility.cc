--- ext/qt/gstqtglutility.cc.orig	2021-08-02 23:37:36 UTC
+++ ext/qt/gstqtglutility.cc
@@ -62,10 +62,10 @@ gst_qt_get_gl_display ()
 
   g_assert (app != NULL);
 
-  if (g_once_init_enter (&_debug)) {
+  if (g_once_init_enter ((unsigned long *)&_debug)) {
     GST_DEBUG_CATEGORY_INIT (GST_CAT_DEFAULT, "qtglutility", 0,
         "Qt gl utility functions");
-    g_once_init_leave (&_debug, 1);
+    g_once_init_leave ((unsigned long *)&_debug, 1);
   }
   GST_INFO ("QGuiApplication::instance()->platformName() %s", app->platformName().toUtf8().data());
 
