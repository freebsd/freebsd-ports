--- src/3rdparty/chromium/ui/message_center/views/message_view_factory.cc.orig	2017-01-26 00:49:32 UTC
+++ src/3rdparty/chromium/ui/message_center/views/message_view_factory.cc
@@ -43,7 +43,7 @@ MessageView* MessageViewFactory::Create(
       notification_view = new NotificationView(controller, notification);
   }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Don't create shadows for notification toasts on linux wih aura.
   if (top_level)
     return notification_view;
