--- chrome/browser/ui/webui/ntp/app_launcher_handler.cc.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/ui/webui/ntp/app_launcher_handler.cc
@@ -312,7 +312,7 @@ base::Value::Dict AppLauncherHandler::CreateExtensionI
   bool is_deprecated_app = false;
   auto* context = extension_service_->GetBrowserContext();
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   is_deprecated_app =
       extensions::IsExtensionUnsupportedDeprecatedApp(context, extension->id());
 #endif
