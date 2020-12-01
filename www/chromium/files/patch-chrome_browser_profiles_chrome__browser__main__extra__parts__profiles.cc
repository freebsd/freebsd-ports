--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2020-11-13 06:36:37 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -304,7 +304,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   media_router::MediaRouterUIServiceFactory::GetInstance();
 #endif
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
   ModelTypeStoreServiceFactory::GetInstance();
