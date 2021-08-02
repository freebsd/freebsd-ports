--- ext/qt/qtitem.cc.orig	2021-08-02 23:44:43 UTC
+++ ext/qt/qtitem.cc
@@ -104,7 +104,7 @@ QtGLVideoItem::QtGLVideoItem()
 {
   static volatile gsize _debug;
 
-  if (g_once_init_enter (&_debug)) {
+  if (g_once_init_enter ((unsigned long *)&_debug)) {
     GST_DEBUG_CATEGORY_INIT (GST_CAT_DEFAULT, "qtglwidget", 0, "Qt GL Widget");
     g_once_init_leave (&_debug, 1);
   }
