--- chrome/common/chrome_switches.cc.orig	2025-10-28 14:29:43 UTC
+++ chrome/common/chrome_switches.cc
@@ -914,7 +914,7 @@ const char kDebugPrint[] = "debug-print";
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kEnableNewAppMenuIcon[] = "enable-new-app-menu-icon";
 
 // Causes the browser to launch directly in guest mode.
@@ -950,7 +950,7 @@ const char kGlicHostLogging[] = "glic-host-logging";
 const char kGlicAdminRedirectPatterns[] = "glic-admin-redirect-patterns";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Writes open and installed web apps for each profile to the specified file
 // without launching a new browser window or tab. Pass a absolute file path
 // to specify where to output the information. Can be used together with
