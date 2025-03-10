--- chrome/common/chrome_switches.h.orig	2025-03-05 08:14:56 UTC
+++ chrome/common/chrome_switches.h
@@ -275,7 +275,7 @@ extern const char kAllowNaClSocketAPI[];
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kEnableNewAppMenuIcon[];
 extern const char kGuest[];
 extern const char kForceNtpMobilePromo[];
@@ -288,7 +288,7 @@ extern const char kGlicAlwaysOpenFre[];
 extern const char kGlicFreURL[];
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kListApps[];
 extern const char kProfileBaseName[];
 extern const char kProfileManagementAttributes[];
