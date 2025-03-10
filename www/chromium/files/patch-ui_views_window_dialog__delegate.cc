--- ui/views/window/dialog_delegate.cc.orig	2025-03-05 08:14:56 UTC
+++ ui/views/window/dialog_delegate.cc
@@ -105,7 +105,7 @@ Widget* DialogDelegate::CreateDialogWidget(
 
 // static
 bool DialogDelegate::CanSupportCustomFrame(gfx::NativeView parent) {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_DESKTOP_AURA)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_DESKTOP_AURA)
   // The new style doesn't support unparented dialogs on Linux desktop.
   return parent != nullptr;
 #else
