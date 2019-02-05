--- Telegram/SourceFiles/core/launcher.cpp.orig	2019-02-01 12:51:46 UTC
+++ Telegram/SourceFiles/core/launcher.cpp
@@ -15,6 +15,8 @@ https://github.com/telegramdesktop/tdesktop/blob/maste
 #include "core/sandbox.h"
 #include "base/concurrent_timer.h"
 
+#include "FREEBSD_QT_PLUGINDIR.h"
+
 namespace Core {
 namespace {
 
@@ -208,9 +210,10 @@ void Launcher::init() {
 
 	QApplication::setApplicationName(qsl("TelegramDesktop"));
 
-#ifndef OS_MAC_OLD
+#if !defined(Q_OS_MAC) && QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
+	// Retina display support is working fine, others are not.
 	QApplication::setAttribute(Qt::AA_DisableHighDpiScaling, true);
-#endif // OS_MAC_OLD
+#endif // not defined Q_OS_MAC and QT_VERSION >= 5.6.0
 
 	initHook();
 }
@@ -228,6 +231,11 @@ int Launcher::exec() {
 	Logs::start(this); // must be started before Platform is started
 	Platform::start(); // must be started before Sandbox is created
 
+	// I don't know why path is not in QT_PLUGIN_PATH by default
+	QCoreApplication::addLibraryPath(FREEBSD_QT_PLUGINDIR);
+	// Telegram doesn't start when extraordinary theme is set, see launchpad.net/bugs/1680943
+	unsetenv("QT_QPA_PLATFORMTHEME");
+
 	auto result = executeApplication();
 
 	DEBUG_LOG(("Telegram finished, result: %1").arg(result));
@@ -329,6 +337,9 @@ void Launcher::prepareSettings() {
 	break;
 	case dbipLinux32:
 		gPlatformString = qsl("Linux32bit");
+	break;
+	case dbipFreeBSD:
+		gPlatformString = qsl("FreeBSD");
 	break;
 	}
 
