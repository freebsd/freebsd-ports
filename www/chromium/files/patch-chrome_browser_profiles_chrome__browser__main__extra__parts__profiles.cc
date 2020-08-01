--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2020-07-07 21:58:13 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -301,7 +301,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   media_router::MediaRouterUIServiceFactory::GetInstance();
 #endif
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
   ModelTypeStoreServiceFactory::GetInstance();
