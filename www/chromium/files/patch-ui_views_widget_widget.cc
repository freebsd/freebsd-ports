--- ui/views/widget/widget.cc.orig	2021-09-24 04:26:39 UTC
+++ ui/views/widget/widget.cc
@@ -51,7 +51,7 @@
 #include "ui/views/window/custom_frame_view.h"
 #include "ui/views/window/dialog_delegate.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -1777,7 +1777,7 @@ const ui::NativeTheme* Widget::GetNativeTheme() const 
       parent_)
     return parent_->GetNativeTheme();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (const views::LinuxUI* linux_ui = views::LinuxUI::instance()) {
     if (auto* native_theme = linux_ui->GetNativeTheme(GetNativeWindow()))
       return native_theme;
