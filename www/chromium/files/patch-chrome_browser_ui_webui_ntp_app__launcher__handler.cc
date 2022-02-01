--- chrome/browser/ui/webui/ntp/app_launcher_handler.cc.orig	2021-12-31 00:57:25 UTC
+++ chrome/browser/ui/webui/ntp/app_launcher_handler.cc
@@ -314,7 +314,7 @@ void AppLauncherHandler::CreateExtensionInfo(const Ext
       base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kKioskMode));
 
   bool is_deprecated_app = false;
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
   is_deprecated_app = extensions::IsExtensionUnsupportedDeprecatedApp(
       extension_service_->GetBrowserContext(), extension->id());
 #endif
@@ -764,7 +764,7 @@ void AppLauncherHandler::HandleLaunchApp(const base::L
 
   Profile* profile = extension_service_->profile();
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
   if (extensions::IsExtensionUnsupportedDeprecatedApp(profile, extension_id)) {
     // TODO(crbug.com/1225779): Show the deprecated apps dialog.
     return;
@@ -1363,7 +1363,7 @@ void AppLauncherHandler::InstallOsHooks(const web_app:
   options.os_hooks[web_app::OsHookType::kRunOnOsLogin] = false;
   options.os_hooks[web_app::OsHookType::kUninstallationViaOsSettings] = true;
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   options.os_hooks[web_app::OsHookType::kUrlHandlers] = true;
 #else
   options.os_hooks[web_app::OsHookType::kUrlHandlers] = false;
