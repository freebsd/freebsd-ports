--- Telegram/lib_base/base/platform/base_platform_info.h.orig	2020-01-29 09:41:30 UTC
+++ Telegram/lib_base/base/platform/base_platform_info.h
@@ -53,8 +53,8 @@ void Finish();
 
 #ifdef Q_OS_MAC
 #include "base/platform/mac/base_info_mac.h"
-#elif defined Q_OS_LINUX // Q_OS_MAC
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD // Q_OS_MAC
 #include "base/platform/linux/base_info_linux.h"
-#elif defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX
+#elif defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINU || Q_OS_FREEBSD X
 #include "base/platform/win/base_info_win.h"
-#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WIN
+#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WIN || Q_OS_FREEBSD X
