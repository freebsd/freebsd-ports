--- Telegram/SourceFiles/ui/platform/ui_platform_utility.h.orig	2019-10-07 15:58:21 UTC
+++ Telegram/SourceFiles/ui/platform/ui_platform_utility.h
@@ -37,8 +37,8 @@ void DrainMainQueue(); // Needed only if UseMainQueueG
 
 #ifdef Q_OS_MAC
 #include "ui/platform/mac/ui_platform_utility_mac.h"
-#elif defined Q_OS_LINUX // Q_OS_MAC
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD // Q_OS_MAC
 #include "ui/platform/linux/ui_platform_utility_linux.h"
-#elif defined Q_OS_WINRT || defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX
+#elif defined Q_OS_WINRT || defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX || Q_OS_FREEBSD
 #include "ui/platform/win/ui_platform_utility_win.h"
-#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || Q_OS_WIN
+#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || Q_OS_WIN || Q_OS_FREEBSD
