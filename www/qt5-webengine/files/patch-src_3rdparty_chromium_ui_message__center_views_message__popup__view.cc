--- src/3rdparty/chromium/ui/message_center/views/message_popup_view.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/message_center/views/message_popup_view.cc
@@ -110,7 +110,7 @@ void MessagePopupView::Show() {
 void MessagePopupView::Show() {
   views::Widget::InitParams params(views::Widget::InitParams::TYPE_POPUP);
   params.z_order = ui::ZOrderLevel::kFloatingWindow;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // Make the widget explicitly activatable as TYPE_POPUP is not activatable by
   // default but we need focus for the inline reply textarea.
   params.activatable = views::Widget::InitParams::ACTIVATABLE_YES;
