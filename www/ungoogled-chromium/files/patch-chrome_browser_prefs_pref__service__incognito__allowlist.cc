--- chrome/browser/prefs/pref_service_incognito_allowlist.cc.orig	2023-08-18 10:26:52 UTC
+++ chrome/browser/prefs/pref_service_incognito_allowlist.cc
@@ -168,7 +168,7 @@ const char* const kPersistentPrefNames[] = {
     prefs::kShowFullscreenToolbar,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Toggleing custom frames affects all open windows in the profile, hence
     // should be written to the regular profile when changed in incognito mode.
     prefs::kUseCustomChromeFrame,
