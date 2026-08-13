--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.h.orig	2026-08-13 07:41:05 UTC
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.h
@@ -264,7 +264,7 @@ class WebAppUiManagerImpl : public BrowserCollectionOb
       webapps::UninstallResultCode uninstall_code);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void ShowIPHPromoForAppsLaunchedViaLinkCapturing(Browser* browser,
                                                    const webapps::AppId& app_id,
                                                    bool is_activated);
