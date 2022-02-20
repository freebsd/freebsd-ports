--- chrome/browser/web_applications/externally_managed_app_install_task.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/web_applications/externally_managed_app_install_task.cc
@@ -310,7 +310,7 @@ void ExternallyManagedAppInstallTask::OnWebAppInstalle
   const WebApp* web_app = registrar_->GetAppById(app_id);
   options.os_hooks[OsHookType::kUninstallationViaOsSettings] =
       web_app->CanUserUninstallWebApp();
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
   options.os_hooks[OsHookType::kUrlHandlers] = true;
 #else
