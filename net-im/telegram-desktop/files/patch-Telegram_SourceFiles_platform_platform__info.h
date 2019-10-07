--- Telegram/SourceFiles/platform/platform_info.h.orig	2019-09-27 17:04:25 UTC
+++ Telegram/SourceFiles/platform/platform_info.h
@@ -51,4 +51,6 @@ namespace Platform {
 #include "platform/linux/info_linux.h"
 #elif defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX
 #include "platform/win/info_win.h"
-#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WIN
+#elif defined Q_OS_FREEBSD // Q_OS_MAC || Q_OS_LINUX || Q_OS_WIN
+#include "platform/freebsd/info_freebsd.h"
+#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WIN || Q_OS_FREEBSD
