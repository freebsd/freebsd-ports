--- Telegram/SourceFiles/platform/platform_notifications_manager.h.orig	2018-08-04 18:53:40 UTC
+++ Telegram/SourceFiles/platform/platform_notifications_manager.h
@@ -26,8 +26,8 @@ void FlashBounce();
 
 #ifdef Q_OS_MAC
 #include "platform/mac/notifications_manager_mac.h"
-#elif defined Q_OS_LINUX // Q_OS_MAC
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD // Q_OS_MAC
 #include "platform/linux/notifications_manager_linux.h"
-#elif defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX
+#elif defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX || Q_OS_FREEBSD
 #include "platform/win/notifications_manager_win.h"
-#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WIN
+#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WIN || Q_OS_FREEBSD
