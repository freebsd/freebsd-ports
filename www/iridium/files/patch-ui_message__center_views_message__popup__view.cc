--- ui/message_center/views/message_popup_view.cc.orig	2019-03-11 22:01:19 UTC
+++ ui/message_center/views/message_popup_view.cc
@@ -114,7 +114,7 @@ void MessagePopupView::AutoCollapse() {
 void MessagePopupView::Show() {
   views::Widget::InitParams params(views::Widget::InitParams::TYPE_POPUP);
   params.keep_on_top = true;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   params.opacity = views::Widget::InitParams::OPAQUE_WINDOW;
 #else
   params.opacity = views::Widget::InitParams::TRANSLUCENT_WINDOW;
