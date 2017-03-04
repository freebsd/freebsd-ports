--- ui/message_center/views/toast_contents_view.cc.orig	2017-02-02 02:03:13 UTC
+++ ui/message_center/views/toast_contents_view.cc
@@ -361,7 +361,7 @@ void ToastContentsView::CreateWidget(
     PopupAlignmentDelegate* alignment_delegate) {
   views::Widget::InitParams params(views::Widget::InitParams::TYPE_POPUP);
   params.keep_on_top = true;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   params.opacity = views::Widget::InitParams::OPAQUE_WINDOW;
 #else
   params.opacity = views::Widget::InitParams::TRANSLUCENT_WINDOW;
