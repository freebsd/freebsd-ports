--- chrome/browser/notifications/message_center_notification_manager.cc.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/notifications/message_center_notification_manager.cc
@@ -62,7 +62,7 @@ MessageCenterNotificationManager::MessageCenterNotific
       base::MakeUnique<FullscreenNotificationBlocker>(message_center));
 
 #if defined(OS_WIN) || defined(OS_MACOSX) \
-  || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+  || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // On Windows, Linux and Mac, the notification manager owns the tray icon and
   // views.Other platforms have global ownership and Create will return NULL.
   tray_.reset(message_center::CreateMessageCenterTray());
