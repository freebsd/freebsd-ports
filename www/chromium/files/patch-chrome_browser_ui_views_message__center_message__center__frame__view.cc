--- chrome/browser/ui/views/message_center/message_center_frame_view.cc.orig	2017-01-26 00:49:09 UTC
+++ chrome/browser/ui/views/message_center/message_center_frame_view.cc
@@ -15,7 +15,7 @@
 namespace message_center {
 
 MessageCenterFrameView::MessageCenterFrameView() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   const int kBorderWidth = 1;
   SetBorder(views::CreateSolidBorder(
       kBorderWidth, message_center::kMessageCenterBorderColor));
