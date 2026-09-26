--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.h.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.h
@@ -263,7 +263,7 @@ class WebAppUiManagerImpl : public BrowserCollectionOb
       webapps::UninstallResultCode uninstall_code);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void ShowIPHPromoForAppsLaunchedViaLinkCapturing(
       BrowserWindowInterface* browser,
       const webapps::AppId& app_id,
