--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2020-09-08 19:14:00 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -310,7 +310,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   media_router::MediaRouterUIServiceFactory::GetInstance();
 #endif
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
   ModelTypeStoreServiceFactory::GetInstance();
