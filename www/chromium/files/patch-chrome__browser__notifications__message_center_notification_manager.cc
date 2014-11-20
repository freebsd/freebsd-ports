--- chrome/browser/notifications/message_center_notification_manager.cc.orig	2014-10-10 09:15:30 UTC
+++ chrome/browser/notifications/message_center_notification_manager.cc
@@ -82,7 +82,7 @@
   blockers_.push_back(new FullscreenNotificationBlocker(message_center));
 
 #if defined(OS_WIN) || defined(OS_MACOSX) \
-  || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+  || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // On Windows, Linux and Mac, the notification manager owns the tray icon and
   // views.Other platforms have global ownership and Create will return NULL.
   tray_.reset(message_center::CreateMessageCenterTray());
