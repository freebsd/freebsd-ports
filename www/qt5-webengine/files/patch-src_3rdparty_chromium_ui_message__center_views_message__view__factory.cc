--- src/3rdparty/chromium/ui/message_center/views/message_view_factory.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/message_center/views/message_view_factory.cc
@@ -57,7 +57,7 @@ MessageView* MessageViewFactory::Create(const Notifica
       notification_view = new NotificationView(notification);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Don't create shadows for notification toasts on Linux or CrOS.
   if (top_level)
     return notification_view;
