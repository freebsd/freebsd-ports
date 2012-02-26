--- qdvdauthor/qplayer/engines/kxinewidget.cpp.orig
+++ qdvdauthor/qplayer/engines/kxinewidget.cpp
@@ -2494,7 +2494,11 @@ void KXineWidget::getAutoplayPlugins(QSt
 
 bool KXineWidget::getAutoplayPluginURLS(const QString& plugin, QStringList& list)
 {
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 	char** urls = NULL;
+#else
+	const char* const* urls = NULL;
+#endif
 	int num;
 	int i = 0;
 
