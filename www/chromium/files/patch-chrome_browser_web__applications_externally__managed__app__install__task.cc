--- chrome/browser/web_applications/externally_managed_app_install_task.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/web_applications/externally_managed_app_install_task.cc
@@ -363,7 +363,7 @@ void ExternallyManagedAppInstallTask::OnWebAppInstalle
   const WebApp* web_app = registrar_->GetAppById(app_id);
   options.os_hooks[OsHookType::kUninstallationViaOsSettings] =
       web_app->CanUserUninstallWebApp();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
   options.os_hooks[OsHookType::kUrlHandlers] = true;
 #else
