--- chrome/common/chrome_switches.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/common/chrome_switches.cc
@@ -963,7 +963,7 @@ const char kDebugPrint[] = "debug-print";
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kEnableNewAppMenuIcon[] = "enable-new-app-menu-icon";
 
 // Causes the browser to launch directly in guest mode.
@@ -1016,7 +1016,7 @@ const char kGlicGuestUrlPresetPreprod[] = "glic-guest-
 const char kGlicGuestUrlPresetProd[] = "glic-guest-url-preset-prod";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Writes open and installed web apps for each profile to the specified file
 // without launching a new browser window or tab. Pass a absolute file path
 // to specify where to output the information. Can be used together with
