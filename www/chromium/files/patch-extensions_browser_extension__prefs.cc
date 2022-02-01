--- extensions/browser/extension_prefs.cc.orig	2021-12-31 00:57:34 UTC
+++ extensions/browser/extension_prefs.cc
@@ -2260,7 +2260,7 @@ void ExtensionPrefs::RegisterProfilePrefs(
   registry->RegisterStringPref(pref_names::kLastChromeVersion, std::string());
   registry->RegisterDictionaryPref(kInstallSignature);
   registry->RegisterListPref(kExternalUninstalls);
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
   registry->RegisterBooleanPref(pref_names::kChromeAppsEnabled, false);
 #endif
   registry->RegisterBooleanPref(pref_names::kU2fSecurityKeyApiEnabled, false);
