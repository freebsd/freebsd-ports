--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc
@@ -350,7 +350,7 @@ bool WebAppUiManagerImpl::IsAppMigrationDialogShowing(
     return false;
   }
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   BrowserView* browser_view = BrowserView::GetBrowserViewForBrowser(window);
   return browser_view &&
          browser_view->GetProperty(kIsPwaUpdateDialogShowingKey) &&
@@ -1024,7 +1024,7 @@ void WebAppUiManagerImpl::ClearWebAppSiteDataIfNeeded(
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 const base::Feature& GetPromoFeatureEngagementFromBrowser(
     const BrowserWindowInterface* browser) {
