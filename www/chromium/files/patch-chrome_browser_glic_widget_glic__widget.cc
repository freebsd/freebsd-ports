--- chrome/browser/glic/widget/glic_widget.cc.orig	2025-12-05 10:12:50 UTC
+++ chrome/browser/glic/widget/glic_widget.cc
@@ -48,7 +48,7 @@
 #include "ui/views/win/hwnd_util.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
@@ -283,7 +283,7 @@ std::unique_ptr<GlicWidget> GlicWidget::Create(views::
 #if BUILDFLAG(IS_MAC)
   params.animation_enabled = true;
 #endif  // BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   params.wm_class_class = shell_integration_linux::GetProgramClassClass();
   params.wayland_app_id = params.wm_class_class + "-glic";
 #endif  // BUILDFLAG(IS_LINUX)
