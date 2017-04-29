--- ui/message_center/views/toast_contents_view.cc.orig	2017-04-19 19:06:54 UTC
+++ ui/message_center/views/toast_contents_view.cc
@@ -388,7 +388,7 @@ void ToastContentsView::CreateWidget(
     PopupAlignmentDelegate* alignment_delegate) {
   views::Widget::InitParams params(views::Widget::InitParams::TYPE_POPUP);
   params.keep_on_top = true;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   params.opacity = views::Widget::InitParams::OPAQUE_WINDOW;
 #else
   params.opacity = views::Widget::InitParams::TRANSLUCENT_WINDOW;
