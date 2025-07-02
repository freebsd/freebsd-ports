--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2025-07-02 06:08:04 UTC
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -28,7 +28,7 @@
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
