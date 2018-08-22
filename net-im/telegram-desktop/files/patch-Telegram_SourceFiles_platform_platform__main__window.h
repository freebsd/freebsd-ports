--- Telegram/SourceFiles/platform/platform_main_window.h.orig	2018-08-04 18:53:40 UTC
+++ Telegram/SourceFiles/platform/platform_main_window.h
@@ -19,8 +19,8 @@ class MainWindow;
 
 #ifdef Q_OS_MAC
 #include "platform/mac/main_window_mac.h"
-#elif defined Q_OS_LINUX // Q_OS_MAC
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD // Q_OS_MAC
 #include "platform/linux/main_window_linux.h"
-#elif defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX
+#elif defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX || Q_OS_FREEBSD
 #include "platform/win/main_window_win.h"
-#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WIN
+#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WIN || Q_OS_FREEBSD
