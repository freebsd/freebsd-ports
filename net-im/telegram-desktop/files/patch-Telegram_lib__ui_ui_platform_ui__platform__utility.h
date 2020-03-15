--- Telegram/lib_ui/ui/platform/ui_platform_utility.h.orig	2020-02-10 08:12:05 UTC
+++ Telegram/lib_ui/ui/platform/ui_platform_utility.h
@@ -37,7 +37,7 @@ void DrainMainQueue(); // Needed only if UseMainQueueG
 
 #ifdef Q_OS_MAC
 #include "ui/platform/mac/ui_utility_mac.h"
-#elif defined Q_OS_LINUX // Q_OS_MAC
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD // Q_OS_MAC
 #include "ui/platform/linux/ui_utility_linux.h"
 #elif defined Q_OS_WINRT || defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX
 #include "ui/platform/win/ui_utility_win.h"
