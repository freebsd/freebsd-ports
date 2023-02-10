--- chrome/browser/ui/views/eye_dropper/eye_dropper_view.cc.orig	2023-01-17 19:19:00 UTC
+++ chrome/browser/ui/views/eye_dropper/eye_dropper_view.cc
@@ -159,7 +159,7 @@ EyeDropperView::EyeDropperView(content::RenderFrameHos
   // EyeDropper/WidgetDelegate.
   set_owned_by_client();
   SetPreferredSize(GetSize());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use TYPE_MENU for Linux to ensure that the eye dropper view is displayed
   // above the color picker.
   views::Widget::InitParams params(views::Widget::InitParams::TYPE_MENU);
