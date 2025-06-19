--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2025-06-19 07:37:57 UTC
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -24,7 +24,7 @@
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
