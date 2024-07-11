--- chrome/browser/prefs/pref_service_incognito_allowlist.cc.orig	2024-06-22 08:49:42 UTC
+++ chrome/browser/prefs/pref_service_incognito_allowlist.cc
@@ -184,7 +184,7 @@ const char* const kPersistentPrefNames[] = {
     prefs::kShowFullscreenToolbar,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Toggleing custom frames affects all open windows in the profile, hence
     // should be written to the regular profile when changed in incognito mode.
     prefs::kUseCustomChromeFrame,
