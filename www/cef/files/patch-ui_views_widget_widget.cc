--- ui/views/widget/widget.cc.orig	2026-08-31 10:59:09 UTC
+++ ui/views/widget/widget.cc
@@ -72,7 +72,7 @@
 #include "ui/views/window/dialog_delegate.h"
 #include "ui/wm/core/window_properties.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -2759,7 +2759,7 @@ const ui::NativeTheme* Widget::GetNativeTheme() const 
     return parent_->GetNativeTheme();
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui_theme =
           ui::LinuxUiTheme::GetForWindow(GetNativeWindow())) {
     return linux_ui_theme->GetNativeTheme();
