--- ui/views/widget/widget.cc.orig	2025-12-05 10:12:50 UTC
+++ ui/views/widget/widget.cc
@@ -64,7 +64,7 @@
 #include "ui/views/widget/widget_removals_observer.h"
 #include "ui/views/window/dialog_delegate.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -2545,7 +2545,7 @@ const ui::NativeTheme* Widget::GetNativeTheme() const 
     return parent_->GetNativeTheme();
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui_theme =
           ui::LinuxUiTheme::GetForWindow(GetNativeWindow())) {
     return linux_ui_theme->GetNativeTheme();
