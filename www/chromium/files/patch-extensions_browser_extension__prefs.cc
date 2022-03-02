--- extensions/browser/extension_prefs.cc.orig	2022-02-28 16:54:41 UTC
+++ extensions/browser/extension_prefs.cc
@@ -2265,7 +2265,7 @@ void ExtensionPrefs::RegisterProfilePrefs(
   registry->RegisterStringPref(pref_names::kLastChromeVersion, std::string());
   registry->RegisterDictionaryPref(kInstallSignature);
   registry->RegisterListPref(kExternalUninstalls);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(pref_names::kChromeAppsEnabled, false);
 #endif
   registry->RegisterBooleanPref(pref_names::kU2fSecurityKeyApiEnabled, false);
