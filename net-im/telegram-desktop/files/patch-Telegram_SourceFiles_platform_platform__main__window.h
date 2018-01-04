--- Telegram/SourceFiles/platform/platform_main_window.h.orig	2017-09-05 17:38:38 UTC
+++ Telegram/SourceFiles/platform/platform_main_window.h
@@ -32,8 +32,8 @@ class MainWindow;
 
 #ifdef Q_OS_MAC
 #include "platform/mac/main_window_mac.h"
-#elif defined Q_OS_LINUX // Q_OS_MAC
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) // Q_OS_MAC
 #include "platform/linux/main_window_linux.h"
-#elif defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX
+#elif defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX || Q_OS_FREEBSD
 #include "platform/win/main_window_win.h"
-#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WIN
+#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WIN || Q_OS_FREEBSD
