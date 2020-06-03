--- ui/views/window/dialog_delegate.cc.orig	2020-05-13 18:40:37 UTC
+++ ui/views/window/dialog_delegate.cc
@@ -59,7 +59,7 @@ Widget* DialogDelegate::CreateDialogWidget(WidgetDeleg
 
 // static
 bool DialogDelegate::CanSupportCustomFrame(gfx::NativeView parent) {
-#if defined(OS_LINUX) && BUILDFLAG(ENABLE_DESKTOP_AURA)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(ENABLE_DESKTOP_AURA)
   // The new style doesn't support unparented dialogs on Linux desktop.
   return parent != nullptr;
 #else
