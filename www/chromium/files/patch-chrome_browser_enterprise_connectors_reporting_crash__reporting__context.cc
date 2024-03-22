--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2024-03-22 08:19:40 UTC
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -18,7 +18,7 @@
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
