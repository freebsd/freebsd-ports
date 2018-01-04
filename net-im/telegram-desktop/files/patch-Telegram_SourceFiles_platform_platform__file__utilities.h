--- Telegram/SourceFiles/platform/platform_file_utilities.h.orig	2017-09-05 17:38:38 UTC
+++ Telegram/SourceFiles/platform/platform_file_utilities.h
@@ -51,8 +51,8 @@ bool Get(QStringList &files, QByteArray 
 
 #ifdef Q_OS_MAC
 #include "platform/mac/file_utilities_mac.h"
-#elif defined Q_OS_LINUX // Q_OS_MAC
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) // Q_OS_MAC
 #include "platform/linux/file_utilities_linux.h"
-#elif defined Q_OS_WINRT || defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX
+#elif defined Q_OS_WINRT || defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX || Q_OS_FREEBSD
 #include "platform/win/file_utilities_win.h"
-#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || Q_OS_WIN
+#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || Q_OS_WIN || Q_OS_FREEBSD
