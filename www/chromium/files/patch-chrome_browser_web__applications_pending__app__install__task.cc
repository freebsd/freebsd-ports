--- chrome/browser/web_applications/pending_app_install_task.cc.orig	2021-04-22 07:59:39 UTC
+++ chrome/browser/web_applications/pending_app_install_task.cc
@@ -310,7 +310,7 @@ void PendingAppInstallTask::OnWebAppInstalled(bool is_
   options.os_hooks[OsHookType::kProtocolHandlers] = true;
   options.os_hooks[OsHookType::kUninstallationViaOsSettings] = true;
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   options.os_hooks[web_app::OsHookType::kUrlHandlers] = true;
 #else
   options.os_hooks[web_app::OsHookType::kUrlHandlers] = false;
