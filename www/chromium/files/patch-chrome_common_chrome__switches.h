--- chrome/common/chrome_switches.h.orig	2025-12-05 10:12:50 UTC
+++ chrome/common/chrome_switches.h
@@ -284,7 +284,7 @@ extern const char kDebugPrint[];
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kEnableNewAppMenuIcon[];
 extern const char kGuest[];
 extern const char kForceNtpMobilePromo[];
@@ -304,7 +304,7 @@ extern const char kGlicHostLogging[];
 extern const char kGlicAdminRedirectPatterns[];
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kListApps[];
 extern const char kProfileBaseName[];
 extern const char kProfileManagementAttributes[];
