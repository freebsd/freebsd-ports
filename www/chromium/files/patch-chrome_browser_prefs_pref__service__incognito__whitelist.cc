--- chrome/browser/prefs/pref_service_incognito_whitelist.cc.orig	2019-06-04 18:55:17 UTC
+++ chrome/browser/prefs/pref_service_incognito_whitelist.cc
@@ -183,7 +183,7 @@ const char* const kPersistentPrefNames[] = {
     prefs::kShowFullscreenToolbar,
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
     // Toggleing custom frames affects all open windows in the profile, hence
     // should be written to the regular profile when changed in incognito mode.
     prefs::kUseCustomChromeFrame,
