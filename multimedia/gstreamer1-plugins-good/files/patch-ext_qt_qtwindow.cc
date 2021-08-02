--- ext/qt/qtwindow.cc.orig	2021-08-02 23:46:48 UTC
+++ ext/qt/qtwindow.cc
@@ -107,7 +107,7 @@ QtGLWindow::QtGLWindow ( QWindow * parent, QQuickWindo
 
   g_assert (app != NULL);
 
-  if (g_once_init_enter (&_debug)) {
+  if (g_once_init_enter ((unsigned long *)&_debug)) {
     GST_DEBUG_CATEGORY_INIT (GST_CAT_DEFAULT, "qtglwindow", 0, "Qt GL QuickWindow");
     g_once_init_leave (&_debug, 1);
   }
@@ -153,7 +153,7 @@ QtGLWindow::beforeRendering()
   g_mutex_lock (&this->priv->lock);
 
   static volatile gsize once = 0;
-  if (g_once_init_enter(&once)) {
+  if (g_once_init_enter((unsigned long *)&once)) {
     this->priv->start = QDateTime::currentDateTime().toMSecsSinceEpoch();
     g_once_init_leave(&once,1);
   }
