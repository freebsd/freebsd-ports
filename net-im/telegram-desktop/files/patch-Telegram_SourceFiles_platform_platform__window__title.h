--- Telegram/SourceFiles/platform/platform_window_title.h.orig	2018-02-06 05:56:19 UTC
+++ Telegram/SourceFiles/platform/platform_window_title.h
@@ -25,7 +25,7 @@ void PreviewWindowFramePaint(QImage &pre
 #include "platform/mac/window_title_mac.h"
 #elif defined Q_OS_WIN // Q_OS_MAC
 #include "platform/win/window_title_win.h"
-#elif defined Q_OS_WINRT || defined Q_OS_LINUX // Q_OS_MAC || Q_OS_WIN
+#elif defined Q_OS_WINRT || defined Q_OS_LINUX || defined Q_OS_FREEBSD // Q_OS_MAC || Q_OS_WIN
 
 namespace Platform {
 
@@ -43,4 +43,4 @@ inline void PreviewWindowFramePaint(QIma
 
 } // namespace Platform
 
-#endif // Q_OS_MAC || Q_OS_WIN || Q_OS_WINRT || Q_OS_LINUX
+#endif // Q_OS_MAC || Q_OS_WIN || Q_OS_WINRT || Q_OS_LINUX || Q_OS_FREEBSD
