--- chrome/browser/prefs/pref_service_incognito_allowlist.cc.orig	2021-04-14 18:40:54 UTC
+++ chrome/browser/prefs/pref_service_incognito_allowlist.cc
@@ -138,7 +138,7 @@ const char* const kPersistentPrefNames[] = {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
     // Toggleing custom frames affects all open windows in the profile, hence
     // should be written to the regular profile when changed in incognito mode.
     prefs::kUseCustomChromeFrame,
