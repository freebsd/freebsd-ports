--- chrome/browser/glic/widget/glic_widget.cc.orig	2025-10-28 14:29:43 UTC
+++ chrome/browser/glic/widget/glic_widget.cc
@@ -161,7 +161,7 @@ std::unique_ptr<GlicWidget> GlicWidget::Create(
   // Don't change this name. This is used by other code to identify the glic
   // window. See b/404947780.
   params.name = "GlicWidget";
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   params.wm_class_class = shell_integration_linux::GetProgramClassClass();
   params.wayland_app_id = params.wm_class_class + "-glic";
 #endif
