--- chrome/browser/devtools/devtools_window.cc.orig	2025-11-01 06:40:37 UTC
+++ chrome/browser/devtools/devtools_window.cc
@@ -566,7 +566,7 @@ void DevToolsWindow::RegisterProfilePrefs(
       prefs::kDevToolsGoogleDeveloperProgramProfileAvailability,
       /* enabled */ 0);
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   registry->RegisterListPref(prefs::kDeveloperToolsAvailabilityAllowlist);
   registry->RegisterListPref(prefs::kDeveloperToolsAvailabilityBlocklist);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) ||
