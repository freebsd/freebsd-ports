--- Telegram/SourceFiles/platform/platform_specific.h.orig	2019-10-07 15:58:21 UTC
+++ Telegram/SourceFiles/platform/platform_specific.h
@@ -51,8 +51,8 @@ void finish();
 
 #ifdef Q_OS_MAC
 #include "platform/mac/specific_mac.h"
-#elif defined Q_OS_LINUX // Q_OS_MAC
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD // Q_OS_MAC
 #include "platform/linux/specific_linux.h"
-#elif defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX
+#elif defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX || Q_OS_FREEBSD
 #include "platform/win/specific_win.h"
-#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WIN
+#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WIN || Q_OS_FREEBSD
