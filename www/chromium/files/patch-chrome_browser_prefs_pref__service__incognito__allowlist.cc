--- chrome/browser/prefs/pref_service_incognito_allowlist.cc.orig	2024-11-14 07:57:23 UTC
+++ chrome/browser/prefs/pref_service_incognito_allowlist.cc
@@ -199,7 +199,7 @@ const char* const kPersistentPrefNames[] = {
     prefs::kShowFullscreenToolbar,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Toggleing custom frames affects all open windows in the profile, hence
     // should be written to the regular profile when changed in incognito mode.
     prefs::kUseCustomChromeFrame,
