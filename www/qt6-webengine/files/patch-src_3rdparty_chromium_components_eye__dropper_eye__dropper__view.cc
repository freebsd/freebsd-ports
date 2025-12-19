--- src/3rdparty/chromium/components/eye_dropper/eye_dropper_view.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/eye_dropper/eye_dropper_view.cc
@@ -208,7 +208,7 @@ EyeDropperView::EyeDropperView(gfx::NativeView parent,
   // EyeDropper/WidgetDelegate.
   set_owned_by_client();
   SetPreferredSize(GetSize());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use TYPE_MENU for Linux to ensure that the eye dropper view is displayed
   // above the color picker.
   views::Widget::InitParams params(
