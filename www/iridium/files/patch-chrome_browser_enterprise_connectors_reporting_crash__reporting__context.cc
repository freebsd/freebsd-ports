--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2024-11-04 08:56:03 UTC
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -20,7 +20,7 @@
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
