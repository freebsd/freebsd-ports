--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.h.orig	2024-02-23 21:04:38 UTC
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.h
@@ -221,7 +221,7 @@ class WebAppUiManagerImpl : public BrowserListObserver
       UninstallCompleteCallback uninstall_complete_callback,
       webapps::UninstallResultCode uninstall_code);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void ShowIPHPromoForAppsLaunchedViaLinkCapturing(const Browser* browser,
                                                    const webapps::AppId& app_id,
                                                    bool is_activated);
