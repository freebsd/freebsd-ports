--- chrome/browser/ui/webui/ntp/app_launcher_handler.cc.orig	2023-01-17 19:19:00 UTC
+++ chrome/browser/ui/webui/ntp/app_launcher_handler.cc
@@ -326,7 +326,7 @@ base::Value::Dict AppLauncherHandler::CreateExtensionI
   bool is_deprecated_app = false;
   auto* context = extension_service_->GetBrowserContext();
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   is_deprecated_app =
       extensions::IsExtensionUnsupportedDeprecatedApp(context, extension->id());
 #endif
@@ -1444,7 +1444,7 @@ void AppLauncherHandler::InstallOsHooks(const web_app:
   options.os_hooks[web_app::OsHookType::kUninstallationViaOsSettings] =
       web_app->CanUserUninstallWebApp();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
   options.os_hooks[web_app::OsHookType::kUrlHandlers] = true;
 #else
