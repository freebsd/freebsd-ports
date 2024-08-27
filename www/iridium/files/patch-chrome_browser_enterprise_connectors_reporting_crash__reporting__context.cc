--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2024-08-27 06:28:16 UTC
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -19,7 +19,7 @@
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
