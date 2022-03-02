--- chrome/browser/ui/webui/ntp/app_launcher_handler.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/ui/webui/ntp/app_launcher_handler.cc
@@ -306,7 +306,7 @@ void AppLauncherHandler::CreateExtensionInfo(const Ext
       base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kKioskMode));
 
   bool is_deprecated_app = false;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   is_deprecated_app = extensions::IsExtensionUnsupportedDeprecatedApp(
       extension_service_->GetBrowserContext(), extension->id());
 #endif
@@ -735,7 +735,7 @@ void AppLauncherHandler::HandleLaunchApp(const base::L
 
   Profile* profile = extension_service_->profile();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (extensions::IsExtensionUnsupportedDeprecatedApp(profile, extension_id)) {
     // TODO(crbug.com/1225779): Show the deprecated apps dialog.
     return;
@@ -1328,7 +1328,7 @@ void AppLauncherHandler::InstallOsHooks(const web_app:
   options.os_hooks[web_app::OsHookType::kUninstallationViaOsSettings] =
       web_app->CanUserUninstallWebApp();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
   options.os_hooks[web_app::OsHookType::kUrlHandlers] = true;
 #else
