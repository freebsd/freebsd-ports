--- chrome/browser/prefs/pref_service_incognito_allowlist.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/prefs/pref_service_incognito_allowlist.cc
@@ -139,7 +139,7 @@ const char* const kPersistentPrefNames[] = {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     // Toggleing custom frames affects all open windows in the profile, hence
     // should be written to the regular profile when changed in incognito mode.
     prefs::kUseCustomChromeFrame,
