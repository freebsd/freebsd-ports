--- chrome/browser/prefs/pref_service_incognito_allowlist.cc.orig	2021-01-18 21:28:50 UTC
+++ chrome/browser/prefs/pref_service_incognito_allowlist.cc
@@ -136,7 +136,7 @@ const char* const kPersistentPrefNames[] = {
     prefs::kShowFullscreenToolbar,
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_BSD) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
     // Toggleing custom frames affects all open windows in the profile, hence
     // should be written to the regular profile when changed in incognito mode.
     prefs::kUseCustomChromeFrame,
