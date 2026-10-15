--- components/enterprise/data_controls/core/browser/rule.cc.orig	2026-08-31 10:59:09 UTC
+++ components/enterprise/data_controls/core/browser/rule.cc
@@ -611,7 +611,7 @@ bool Rule::AddUnsupportedAttributeErrors(
               },
           },
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {
               Restriction::kFileDownload,
               {
@@ -731,7 +731,7 @@ bool Rule::AddUnsupportedRestrictionErrors(
           },
 #endif  // BUILDFLAG(ENTERPRISE_SCREENSHOT_PROTECTION)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {
               Restriction::kFileDownload,
               {
