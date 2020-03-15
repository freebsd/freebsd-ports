--- Telegram/SourceFiles/core/launcher.cpp.orig	2020-02-18 08:28:06 UTC
+++ Telegram/SourceFiles/core/launcher.cpp
@@ -248,7 +248,7 @@ void Launcher::init() {
 
 	QApplication::setApplicationName(qsl("TelegramDesktop"));
 
-#if defined(Q_OS_LINUX) && QT_VERSION >= QT_VERSION_CHECK(5, 7, 0)
+#if (defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)) && QT_VERSION >= QT_VERSION_CHECK(5, 7, 0)
 	QApplication::setDesktopFileName(Platform::GetLauncherFilename());
 #endif
 
