--- src/chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc
@@ -461,7 +461,7 @@ bool WebAppUiManagerImpl::IsAppMigration
     return false;
   }
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   BrowserView* browser_view = BrowserView::GetBrowserViewForBrowser(window);
   return browser_view &&
          browser_view->GetProperty(kIsPwaUpdateDialogShowingKey) &&
@@ -1155,7 +1155,7 @@ void WebAppUiManagerImpl::ClearWebAppSit
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 const base::Feature& GetPromoFeatureEngagementFromBrowser(
     const BrowserWindowInterface* browser) {
