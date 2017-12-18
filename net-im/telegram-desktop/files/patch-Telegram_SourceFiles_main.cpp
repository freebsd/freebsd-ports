--- Telegram/SourceFiles/main.cpp.orig	2017-09-05 17:38:38 UTC
+++ Telegram/SourceFiles/main.cpp
@@ -22,10 +22,13 @@ Copyright (c) 2014-2017 John Preston, ht
 #include "platform/platform_specific.h"
 #include "storage/localstorage.h"
 
+#include "FREEBSD_QT_PLUGINDIR.h"
+
 int main(int argc, char *argv[]) {
-#ifndef Q_OS_MAC // Retina display support is working fine, others are not.
+#if !defined(Q_OS_MAC) && QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
+	// Retina display support is working fine, others are not.
 	QCoreApplication::setAttribute(Qt::AA_DisableHighDpiScaling, true);
-#endif // Q_OS_MAC
+#endif // not defined Q_OS_MAC and QT_VERSION >= 5.6.0
 	QCoreApplication::setApplicationName(qsl("TelegramDesktop"));
 
 	InitFromCommandLine(argc, argv);
@@ -39,6 +42,11 @@ int main(int argc, char *argv[]) {
 	Logs::start(); // must be started before Platform is started
 	Platform::start(); // must be started before QApplication is created
 
+	// I don't know why path is not in QT_PLUGIN_PATH by default
+	QCoreApplication::addLibraryPath(FREEBSD_QT_PLUGINDIR);
+	// without this Telegram doesn't start on Ubuntu 17.04 due GTK errors
+	setenv("QT_STYLE_OVERRIDE", "qwerty", false);
+
 	int result = 0;
 	{
 		Application app(argc, argv);
