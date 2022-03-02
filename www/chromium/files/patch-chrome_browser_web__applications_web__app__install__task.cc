--- chrome/browser/web_applications/web_app_install_task.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/web_applications/web_app_install_task.cc
@@ -915,7 +915,7 @@ void WebAppInstallTask::OnInstallFinalizedCreateShortc
         web_app->CanUserUninstallWebApp();
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
   options.os_hooks[OsHookType::kUrlHandlers] = true;
 #else
