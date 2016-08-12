--- ui/message_center/views/message_view_factory.cc.orig	2016-08-03 16:51:43.884486000 -0400
+++ ui/message_center/views/message_view_factory.cc	2016-08-03 16:51:59.171721000 -0400
@@ -43,7 +43,7 @@
       notification_view = new NotificationView(controller, notification);
   }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Don't create shadows for notification toasts on linux wih aura.
   if (top_level)
     return notification_view;
