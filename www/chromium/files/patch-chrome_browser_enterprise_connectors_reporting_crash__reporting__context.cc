--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2024-08-26 12:06:38 UTC
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -19,7 +19,7 @@
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
