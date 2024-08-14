--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc.orig	2024-07-30 11:12:21 UTC
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc
@@ -577,7 +577,7 @@ void WebAppUiManagerImpl::MaybeShowIPHPromoForAppsLaun
     content::WebContents* web_contents,
     Profile* profile,
     const std::string& app_id) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   WebAppProvider* provider = WebAppProvider::GetForWebApps(profile);
   CHECK(provider);
 
@@ -797,7 +797,7 @@ void WebAppUiManagerImpl::ClearWebAppSiteDataIfNeeded(
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WebAppUiManagerImpl::ShowIPHPromoForAppsLaunchedViaLinkCapturing(
     const Browser* browser,
     const webapps::AppId& app_id,
