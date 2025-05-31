--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2025-05-28 14:55:43 UTC
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -24,7 +24,7 @@
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
