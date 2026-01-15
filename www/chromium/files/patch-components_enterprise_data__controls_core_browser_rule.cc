--- components/enterprise/data_controls/core/browser/rule.cc.orig	2026-01-14 08:33:23 UTC
+++ components/enterprise/data_controls/core/browser/rule.cc
@@ -534,7 +534,7 @@ bool Rule::AddUnsupportedAttributeErrors(
               },
           },
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {
               Restriction::kFileDownload,
               {
@@ -617,7 +617,7 @@ bool Rule::AddUnsupportedRestrictionErrors(
           },
 #endif  // BUILDFLAG(ENTERPRISE_SCREENSHOT_PROTECTION)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {
               Restriction::kFileDownload,
               {
