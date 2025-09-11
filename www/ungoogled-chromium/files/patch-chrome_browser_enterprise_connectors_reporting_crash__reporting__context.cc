--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2025-09-10 13:22:16 UTC
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -29,7 +29,7 @@
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
