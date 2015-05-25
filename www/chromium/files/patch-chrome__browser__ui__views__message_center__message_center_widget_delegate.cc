--- chrome/browser/ui/views/message_center/message_center_widget_delegate.cc.orig	2015-04-14 18:18:50.000000000 -0400
+++ chrome/browser/ui/views/message_center/message_center_widget_delegate.cc	2015-04-28 09:46:29.443573000 -0400
@@ -97,7 +97,7 @@
   // immediately after the mouse exists from the bubble, which is a really bad
   // experience. Disable hiding until the bug around the focus is fixed.
   // TODO(erg, pkotwicz): fix the activation issue and then remove this ifdef.
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) || !defined(OS_BSD)
   if (!active) {
     tray_->SendHideMessageCenter();
   }
