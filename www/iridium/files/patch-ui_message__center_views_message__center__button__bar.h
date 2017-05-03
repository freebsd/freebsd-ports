--- ui/message_center/views/message_center_button_bar.h.orig	2017-04-19 19:06:54 UTC
+++ ui/message_center/views/message_center_button_bar.h
@@ -78,7 +78,7 @@ class MessageCenterButtonBar : public vi
   // close-on-deactivation is off. This is a tentative solution. Once pkotwicz
   // Fixes the problem of focus-follow-mouse, close-on-deactivation will be
   // back and this field will be removed. See crbug.com/319516.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   views::ImageButton* close_bubble_button_;
 #endif
 
