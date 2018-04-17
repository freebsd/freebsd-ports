--- Telegram/SourceFiles/window/main_window.h.orig	2018-04-08 17:34:33 UTC
+++ Telegram/SourceFiles/window/main_window.h
@@ -57,7 +57,7 @@ public:
 	}
 
 	void reActivateWindow() {
-#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64
+#if defined Q_OS_LINUX32 || defined Q_OS_LINUX64 || defined Q_OS_FREEBSD
 		onReActivate();
 		QTimer::singleShot(200, this, SLOT(onReActivate()));
 #endif // Q_OS_LINUX32 || Q_OS_LINUX64
