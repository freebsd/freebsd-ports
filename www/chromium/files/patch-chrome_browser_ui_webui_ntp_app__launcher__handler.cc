--- chrome/browser/ui/webui/ntp/app_launcher_handler.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/browser/ui/webui/ntp/app_launcher_handler.cc
@@ -316,7 +316,7 @@ void AppLauncherHandler::CreateExtensionInfo(const Ext
 
   bool is_deprecated_app = false;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   is_deprecated_app = extensions::IsExtensionUnsupportedDeprecatedApp(
       extension_service_->GetBrowserContext(), extension->id());
 #endif
@@ -1379,7 +1379,7 @@ void AppLauncherHandler::InstallOsHooks(const web_app:
   options.os_hooks[web_app::OsHookType::kUninstallationViaOsSettings] =
       web_app->CanUserUninstallWebApp();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
   options.os_hooks[web_app::OsHookType::kUrlHandlers] = true;
 #else
