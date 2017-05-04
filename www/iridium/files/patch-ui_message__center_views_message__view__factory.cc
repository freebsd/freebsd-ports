--- ui/message_center/views/message_view_factory.cc.orig	2017-04-19 19:06:54 UTC
+++ ui/message_center/views/message_view_factory.cc
@@ -43,7 +43,7 @@ MessageView* MessageViewFactory::Create(
       notification_view = new NotificationView(controller, notification);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Don't create shadows for notification toasts on Linux or CrOS.
   if (top_level)
     return notification_view;
