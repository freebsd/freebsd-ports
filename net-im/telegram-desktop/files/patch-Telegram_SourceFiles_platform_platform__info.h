--- Telegram/SourceFiles/platform/platform_info.h.orig	2019-07-07 13:34:35 UTC
+++ Telegram/SourceFiles/platform/platform_info.h
@@ -49,4 +49,6 @@ namespace Platform {
 #include "platform/linux/info_linux.h"
 #elif defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX
 #include "platform/win/info_win.h"
-#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WIN
+#elif defined Q_OS_FREEBSD // Q_OS_MAC || Q_OS_LINUX || Q_OS_WIN
+#include "platform/freebsd/info_freebsd.h"
+#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WIN || Q_OS_FREEBSD
