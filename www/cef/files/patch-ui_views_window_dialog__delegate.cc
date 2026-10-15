--- ui/views/window/dialog_delegate.cc.orig	2026-09-24 16:32:14 UTC
+++ ui/views/window/dialog_delegate.cc
@@ -129,7 +129,7 @@ Widget* DialogDelegate::CreateDialogWidg
 // static
 bool DialogDelegate::CanSupportCustomFrame(gfx::NativeView parent,
                                            gfx::AcceleratedWidget parent_widget) {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_DESKTOP_AURA)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_DESKTOP_AURA)
   // The new style doesn't support unparented dialogs on Linux desktop.
   return parent != nullptr || parent_widget != gfx::kNullAcceleratedWidget;
 #else
