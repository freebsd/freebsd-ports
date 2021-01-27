--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2021-01-18 21:28:50 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -319,7 +319,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   media_router::MediaRouterUIServiceFactory::GetInstance();
 #endif
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
   ModelTypeStoreServiceFactory::GetInstance();
