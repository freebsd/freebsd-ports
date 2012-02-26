--- qdvdauthor/qplayer/engines/qxinewidget.cpp.orig
+++ qdvdauthor/qplayer/engines/qxinewidget.cpp
@@ -1403,7 +1403,11 @@ void QXineWidget::GetAutoplayPlugins(QSt
  
 bool QXineWidget::GetAutoplayPluginMrl(const QString& plugin, QStringList& list)
 {
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
   char** mrls = NULL;
+#else
+  const char* const* mrls = NULL;
+#endif
   int num;
   int i = 0;
 
@@ -1657,7 +1661,7 @@ trick modes 
 #define XINE_TRICK_MODE_FAST_FORWARD       3
 #define XINE_TRICK_MODE_FAST_REWIND        4
 */
-	xine_trick_mode(xineStream, XINE_TRICK_MODE_FAST_REWIND, XINE_SPEED_NORMAL);
+	// xine_trick_mode(xineStream, XINE_TRICK_MODE_FAST_REWIND, XINE_SPEED_NORMAL);
 }
 
 QString QXineWidget::GetSupportedExtensions() const
