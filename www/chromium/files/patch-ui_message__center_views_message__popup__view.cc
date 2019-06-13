--- ui/message_center/views/message_popup_view.cc.orig	2019-06-04 18:55:50 UTC
+++ ui/message_center/views/message_popup_view.cc
@@ -114,7 +114,7 @@ void MessagePopupView::AutoCollapse() {
 void MessagePopupView::Show() {
   views::Widget::InitParams params(views::Widget::InitParams::TYPE_POPUP);
   params.keep_on_top = true;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // Make the widget explicitly activatable as TYPE_POPUP is not activatable by
   // default but we need focus for the inline reply textarea.
   params.activatable = views::Widget::InitParams::ACTIVATABLE_YES;
