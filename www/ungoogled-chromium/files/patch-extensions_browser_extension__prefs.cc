--- extensions/browser/extension_prefs.cc.orig	2023-01-13 08:56:02 UTC
+++ extensions/browser/extension_prefs.cc
@@ -2273,7 +2273,7 @@ void ExtensionPrefs::RegisterProfilePrefs(
   registry->RegisterDictionaryPref(kInstallSignature);
   registry->RegisterListPref(kExternalUninstalls);
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(pref_names::kChromeAppsEnabled, false);
 #endif
 
