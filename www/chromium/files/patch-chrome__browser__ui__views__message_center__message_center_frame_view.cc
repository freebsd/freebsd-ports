--- chrome/browser/ui/views/message_center/message_center_frame_view.cc.orig	2015-04-28 09:47:57.763176000 -0400
+++ chrome/browser/ui/views/message_center/message_center_frame_view.cc	2015-04-28 09:48:19.225959000 -0400
@@ -13,7 +13,7 @@
 namespace message_center {
 
 MessageCenterFrameView::MessageCenterFrameView() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   const int kBorderWidth = 1;
   SetBorder(views::Border::CreateSolidBorder(
       kBorderWidth, message_center::kMessageCenterBorderColor));
