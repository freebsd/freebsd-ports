--- src/3rdparty/chromium/extensions/browser/extension_prefs.cc.orig	2023-08-16 19:50:41 UTC
+++ src/3rdparty/chromium/extensions/browser/extension_prefs.cc
@@ -2230,7 +2230,7 @@ void ExtensionPrefs::RegisterProfilePrefs(
   registry->RegisterListPref(
       pref_names::kExtendedBackgroundLifetimeForPortConnectionsToUrls);
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(pref_names::kChromeAppsEnabled, false);
 #endif
   registry->RegisterBooleanPref(
