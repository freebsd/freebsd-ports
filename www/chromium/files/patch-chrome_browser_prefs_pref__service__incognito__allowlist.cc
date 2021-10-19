--- chrome/browser/prefs/pref_service_incognito_allowlist.cc.orig	2021-09-14 01:51:50 UTC
+++ chrome/browser/prefs/pref_service_incognito_allowlist.cc
@@ -139,7 +139,7 @@ const char* const kPersistentPrefNames[] = {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
     // Toggleing custom frames affects all open windows in the profile, hence
     // should be written to the regular profile when changed in incognito mode.
     prefs::kUseCustomChromeFrame,
