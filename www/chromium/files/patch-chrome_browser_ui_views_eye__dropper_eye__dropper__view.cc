--- chrome/browser/ui/views/eye_dropper/eye_dropper_view.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/ui/views/eye_dropper/eye_dropper_view.cc
@@ -155,7 +155,7 @@ EyeDropperView::EyeDropperView(content::RenderFrameHos
   // EyeDropper/WidgetDelegate.
   set_owned_by_client();
   SetPreferredSize(GetSize());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use TYPE_MENU for Linux to ensure that the eye dropper view is displayed
   // above the color picker.
   views::Widget::InitParams params(views::Widget::InitParams::TYPE_MENU);
