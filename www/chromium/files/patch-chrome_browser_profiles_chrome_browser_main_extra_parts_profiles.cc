--- chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc.orig	2017-09-08 15:53:03.193381000 +0200
+++ chrome/browser/profiles/chrome_browser_main_extra_parts_profiles.cc	2017-09-08 15:54:40.433791000 +0200
@@ -290,7 +290,7 @@
   MediaGalleriesPreferencesFactory::GetInstance();
   NTPResourceCacheFactory::GetInstance();
 #endif
-#if !defined(OS_ANDROID) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX)
+#if !defined(OS_ANDROID) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX) && !defined(OS_BSD)
   feature_engagement_tracker::NewTabTrackerFactory::GetInstance();
 #endif
   ContentSuggestionsServiceFactory::GetInstance();
