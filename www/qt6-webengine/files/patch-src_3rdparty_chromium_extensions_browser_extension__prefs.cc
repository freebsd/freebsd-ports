--- src/3rdparty/chromium/extensions/browser/extension_prefs.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/extensions/browser/extension_prefs.cc
@@ -2289,7 +2289,7 @@ void ExtensionPrefs::RegisterProfilePrefs(
   registry->RegisterDictionaryPref(kInstallSignature);
   registry->RegisterListPref(kExternalUninstalls);
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(pref_names::kChromeAppsEnabled, false);
 #endif
   registry->RegisterBooleanPref(pref_names::kU2fSecurityKeyApiEnabled, false);
