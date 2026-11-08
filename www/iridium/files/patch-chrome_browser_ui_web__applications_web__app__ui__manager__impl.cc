--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc.orig	2026-08-13 16:48:13 UTC
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc
@@ -341,7 +341,7 @@ bool WebAppUiManagerImpl::IsAppMigrationDialogShowing(
     return false;
   }
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   BrowserView* browser_view = BrowserView::GetBrowserViewForBrowser(window);
   return browser_view &&
          browser_view->GetProperty(kIsPwaUpdateDialogShowingKey) &&
@@ -930,7 +930,7 @@ void WebAppUiManagerImpl::ClearWebAppSiteDataIfNeeded(
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 const base::Feature& GetPromoFeatureEngagementFromBrowser(
     const BrowserWindowInterface* browser) {
