--- chrome/browser/ui/webui/ntp/app_launcher_handler.cc.orig	2023-07-16 15:47:57 UTC
+++ chrome/browser/ui/webui/ntp/app_launcher_handler.cc
@@ -321,7 +321,7 @@ base::Value::Dict AppLauncherHandler::CreateExtensionI
   bool is_deprecated_app = false;
   auto* context = extension_service_->GetBrowserContext();
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   is_deprecated_app =
       extensions::IsExtensionUnsupportedDeprecatedApp(context, extension->id());
 #endif
