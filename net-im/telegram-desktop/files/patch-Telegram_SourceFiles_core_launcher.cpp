--- Telegram/SourceFiles/core/launcher.cpp.orig	2018-01-03 10:46:01 UTC
+++ Telegram/SourceFiles/core/launcher.cpp
@@ -13,6 +13,8 @@ https://github.com/telegramdesktop/tdesk
 #include "core/main_queue_processor.h"
 #include "application.h"
 
+#include "FREEBSD_QT_PLUGINDIR.h"
+
 namespace Core {
 
 std::unique_ptr<Launcher> Launcher::Create(int argc, char *argv[]) {
@@ -31,9 +33,10 @@ void Launcher::init() {
 
 	QCoreApplication::setApplicationName(qsl("TelegramDesktop"));
 
-#ifndef OS_MAC_OLD
+#if !defined(Q_OS_MAC) && QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
+	// Retina display support is working fine, others are not.
 	QCoreApplication::setAttribute(Qt::AA_DisableHighDpiScaling, true);
-#endif // OS_MAC_OLD
+#endif // not defined Q_OS_MAC and QT_VERSION >= 5.6.0
 
 	initHook();
 }
@@ -51,6 +54,11 @@ int Launcher::exec() {
 	Logs::start(this); // must be started before Platform is started
 	Platform::start(); // must be started before QApplication is created
 
+	// I don't know why path is not in QT_PLUGIN_PATH by default
+	QCoreApplication::addLibraryPath(FREEBSD_QT_PLUGINDIR);
+	// Telegram doesn't start when extraordinary theme is set, see launchpad.net/bugs/1680943
+	unsetenv("QT_QPA_PLATFORMTHEME");
+
 	auto result = executeApplication();
 
 	DEBUG_LOG(("Telegram finished, result: %1").arg(result));
@@ -136,6 +144,10 @@ void Launcher::prepareSettings() {
 		gUpdateURL = QUrl(qsl("http://tdesktop.com/linux32/tupdates/current"));
 		gPlatformString = qsl("Linux32bit");
 	break;
+	case dbipFreeBSD:
+		gUpdateURL = QUrl(qsl(""));
+		gPlatformString = qsl("FreeBSD");
+	break;
 	}
 
 	auto path = Platform::CurrentExecutablePath(_argc, _argv);
