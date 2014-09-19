--- chrome/browser/notifications/message_center_notification_manager.cc.orig	2014-09-10 01:47:12.000000000 +0200
+++ chrome/browser/notifications/message_center_notification_manager.cc	2014-09-18 14:21:16.000000000 +0200
@@ -78,7 +78,7 @@
   blockers_.push_back(new FullscreenNotificationBlocker(message_center));
 
 #if defined(OS_WIN) || defined(OS_MACOSX) \
-  || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+  || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // On Windows, Linux and Mac, the notification manager owns the tray icon and
   // views.Other platforms have global ownership and Create will return NULL.
   tray_.reset(message_center::CreateMessageCenterTray());
