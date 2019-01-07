--- ui/message_center/views/message_popup_view.cc.orig	2019-01-04 01:03:15.842319000 +0100
+++ ui/message_center/views/message_popup_view.cc	2019-01-04 01:03:49.177126000 +0100
@@ -112,7 +112,7 @@
 void MessagePopupView::Show() {
   views::Widget::InitParams params(views::Widget::InitParams::TYPE_POPUP);
   params.keep_on_top = true;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   params.opacity = views::Widget::InitParams::OPAQUE_WINDOW;
 #else
   params.opacity = views::Widget::InitParams::TRANSLUCENT_WINDOW;
