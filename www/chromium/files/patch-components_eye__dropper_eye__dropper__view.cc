--- components/eye_dropper/eye_dropper_view.cc.orig	2024-07-30 11:12:21 UTC
+++ components/eye_dropper/eye_dropper_view.cc
@@ -202,7 +202,7 @@ EyeDropperView::EyeDropperView(gfx::NativeView parent,
   // EyeDropper/WidgetDelegate.
   set_owned_by_client();
   SetPreferredSize(GetSize());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use TYPE_MENU for Linux to ensure that the eye dropper view is displayed
   // above the color picker.
   views::Widget::InitParams params(
