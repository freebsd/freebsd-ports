--- chrome/browser/ui/views/eye_dropper/eye_dropper_view.cc.orig	2021-09-24 04:26:00 UTC
+++ chrome/browser/ui/views/eye_dropper/eye_dropper_view.cc
@@ -146,7 +146,7 @@ EyeDropperView::EyeDropperView(content::RenderFrameHos
   // EyeDropper/WidgetDelegate.
   set_owned_by_client();
   SetPreferredSize(GetSize());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Use TYPE_MENU for Linux to ensure that the eye dropper view is displayed
   // above the color picker.
   views::Widget::InitParams params(views::Widget::InitParams::TYPE_MENU);
