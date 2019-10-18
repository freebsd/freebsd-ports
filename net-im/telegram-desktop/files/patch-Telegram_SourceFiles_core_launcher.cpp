--- Telegram/SourceFiles/core/launcher.cpp.orig	2019-10-07 15:58:21 UTC
+++ Telegram/SourceFiles/core/launcher.cpp
@@ -17,6 +17,8 @@ https://github.com/telegramdesktop/tdesktop/blob/maste
 #include "base/concurrent_timer.h"
 #include "facades.h"
 
+#include "FREEBSD_QT_PLUGINDIR.h"
+
 namespace Core {
 namespace {
 
@@ -249,12 +251,13 @@ void Launcher::init() {
 #define TDESKTOP_LAUNCHER_FILENAME_TO_STRING_HELPER(V) #V
 #define TDESKTOP_LAUNCHER_FILENAME_TO_STRING(V) TDESKTOP_LAUNCHER_FILENAME_TO_STRING_HELPER(V)
 	QApplication::setDesktopFileName(qsl(TDESKTOP_LAUNCHER_FILENAME_TO_STRING(TDESKTOP_LAUNCHER_FILENAME)));
-#elif defined(Q_OS_LINUX) && QT_VERSION >= QT_VERSION_CHECK(5, 7, 0)
+#elif (defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)) && QT_VERSION >= QT_VERSION_CHECK(5, 7, 0)
 	QApplication::setDesktopFileName(qsl("telegramdesktop.desktop"));
 #endif
-#ifndef OS_MAC_OLD
+#if !defined(Q_OS_MAC) && QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
+	// Retina display support is working fine, others are not.
 	QApplication::setAttribute(Qt::AA_DisableHighDpiScaling, true);
-#endif // OS_MAC_OLD
+#endif // not defined Q_OS_MAC and QT_VERSION >= 5.6.0
 
 	initHook();
 }
@@ -271,6 +274,11 @@ int Launcher::exec() {
 	// both are finished in Sandbox::closeApplication
 	Logs::start(this); // must be started before Platform is started
 	Platform::start(); // must be started before Sandbox is created
+
+	// I don't know why path is not in QT_PLUGIN_PATH by default
+	QCoreApplication::addLibraryPath(FREEBSD_QT_PLUGINDIR);
+	// Telegram doesn't start when extraordinary theme is set, see launchpad.net/bugs/1680943
+	unsetenv("QT_QPA_PLATFORMTHEME");
 
 	auto result = executeApplication();
 
