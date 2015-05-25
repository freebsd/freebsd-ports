--- ui/message_center/views/notification_view.cc.orig	2015-04-14 18:19:00.000000000 -0400
+++ ui/message_center/views/notification_view.cc	2015-04-28 08:22:57.679978000 -0400
@@ -278,7 +278,7 @@
   NotificationView* notification_view =
       new NotificationView(controller, notification);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Don't create shadows for notification toasts on linux wih aura.
   if (top_level)
     return notification_view;
