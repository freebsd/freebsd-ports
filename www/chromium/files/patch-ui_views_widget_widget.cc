--- ui/views/widget/widget.cc.orig	2022-02-28 16:54:41 UTC
+++ ui/views/widget/widget.cc
@@ -51,7 +51,7 @@
 #include "ui/views/window/custom_frame_view.h"
 #include "ui/views/window/dialog_delegate.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -1785,7 +1785,7 @@ const ui::NativeTheme* Widget::GetNativeTheme() const 
       parent_)
     return parent_->GetNativeTheme();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (const views::LinuxUI* linux_ui = views::LinuxUI::instance()) {
     if (auto* native_theme = linux_ui->GetNativeTheme(GetNativeWindow()))
       return native_theme;
