--- Telegram/lib_base/base/platform/base_platform_file_utilities.h.orig	2020-01-29 09:41:30 UTC
+++ Telegram/lib_base/base/platform/base_platform_file_utilities.h
@@ -22,8 +22,8 @@ void RemoveQuarantine(const QString &path);
 
 #ifdef Q_OS_MAC
 #include "base/platform/mac/base_file_utilities_mac.h"
-#elif defined Q_OS_LINUX // Q_OS_MAC
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD // Q_OS_MAC
 #include "base/platform/linux/base_file_utilities_linux.h"
-#elif defined Q_OS_WINRT || defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX
+#elif defined Q_OS_WINRT || defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX || Q_OS_FREEBSD
 #include "base/platform/win/base_file_utilities_win.h"
 #endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || Q_OS_WIN
