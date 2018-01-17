--- src/3rdparty/chromium/ui/message_center/views/message_center_button_bar.h.orig	2017-01-26 00:49:32 UTC
+++ src/3rdparty/chromium/ui/message_center/views/message_center_button_bar.h
@@ -74,7 +74,7 @@ class MessageCenterButtonBar : public vi
   // close-on-deactivation is off. This is a tentative solution. Once pkotwicz
   // Fixes the problem of focus-follow-mouse, close-on-deactivation will be
   // back and this field will be removed. See crbug.com/319516.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   views::ImageButton* close_bubble_button_;
 #endif
 
