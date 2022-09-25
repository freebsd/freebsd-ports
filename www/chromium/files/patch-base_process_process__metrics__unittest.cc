--- base/process/process_metrics_unittest.cc.orig	2022-09-24 10:57:32 UTC
+++ base/process/process_metrics_unittest.cc
@@ -44,7 +44,7 @@ namespace debug {
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||      \
     BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 
 namespace {
 
@@ -347,7 +347,7 @@ TEST_F(SystemMetricsTest, ParseVmstat) {
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||      \
     BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 
 // Test that ProcessMetrics::GetPlatformIndependentCPUUsage() doesn't return
 // negative values when the number of threads running on the process decreases
