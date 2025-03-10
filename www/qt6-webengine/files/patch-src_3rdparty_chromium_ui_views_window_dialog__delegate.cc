--- src/3rdparty/chromium/ui/views/window/dialog_delegate.cc.orig	2023-12-10 06:10:27 UTC
+++ src/3rdparty/chromium/ui/views/window/dialog_delegate.cc
@@ -79,7 +79,7 @@ Widget* DialogDelegate::CreateDialogWidget(
 
 // static
 bool DialogDelegate::CanSupportCustomFrame(gfx::NativeView parent) {
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENABLE_DESKTOP_AURA)
   // The new style doesn't support unparented dialogs on Linux desktop.
   return parent != nullptr;
