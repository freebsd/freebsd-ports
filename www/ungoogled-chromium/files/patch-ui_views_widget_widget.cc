--- ui/views/widget/widget.cc.orig	2023-12-23 12:33:28 UTC
+++ ui/views/widget/widget.cc
@@ -54,7 +54,7 @@
 #include "ui/views/window/custom_frame_view.h"
 #include "ui/views/window/dialog_delegate.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -2068,7 +2068,7 @@ const ui::NativeTheme* Widget::GetNativeTheme() const 
   if (parent_)
     return parent_->GetNativeTheme();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui_theme = ui::LinuxUiTheme::GetForWindow(GetNativeWindow()))
     return linux_ui_theme->GetNativeTheme();
 #endif
