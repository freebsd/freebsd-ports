--- chrome/browser/prefs/pref_service_incognito_whitelist.cc.orig	2020-05-13 18:39:38 UTC
+++ chrome/browser/prefs/pref_service_incognito_whitelist.cc
@@ -133,7 +133,7 @@ const char* const kPersistentPrefNames[] = {
     prefs::kShowFullscreenToolbar,
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
     // Toggleing custom frames affects all open windows in the profile, hence
     // should be written to the regular profile when changed in incognito mode.
     prefs::kUseCustomChromeFrame,
