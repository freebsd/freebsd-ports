--- src/3rdparty/chromium/ui/views/window/dialog_delegate.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/views/window/dialog_delegate.cc
@@ -79,7 +79,7 @@ bool DialogDelegate::CanSupportCustomFrame(gfx::Native
 
 // static
 bool DialogDelegate::CanSupportCustomFrame(gfx::NativeView parent) {
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENABLE_DESKTOP_AURA)
   // The new style doesn't support unparented dialogs on Linux desktop.
   return parent != nullptr;
