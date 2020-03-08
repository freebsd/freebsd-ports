--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2020-03-03 18:53:51 UTC
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc
@@ -292,7 +292,7 @@ void ChromeBrowserMainExtraPartsProfiles::
   if (base::FeatureList::IsEnabled(media::kUseMediaHistoryStore))
     media_history::MediaHistoryKeyedServiceFactory::GetInstance();
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   metrics::DesktopProfileSessionDurationsServiceFactory::GetInstance();
 #endif
   ModelTypeStoreServiceFactory::GetInstance();
