--- components/startup_metric_utils/browser/startup_metric_utils.cc.orig	2026-08-31 10:59:09 UTC
+++ components/startup_metric_utils/browser/startup_metric_utils.cc
@@ -36,11 +36,11 @@
 #elif BUILDFLAG(IS_MAC)
 #include <mach/mach.h>
 #include <mach/task.h>
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/resource.h>
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace {
 
 // These values are taken from the
@@ -296,7 +296,7 @@ BrowserStartupMetricRecorder::GetHardFaultCountForCurr
   }
   return base::saturated_cast<uint32_t>(events_info.pageins);
 }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::optional<uint32_t>
 BrowserStartupMetricRecorder::GetHardFaultCountForCurrentProcess() {
   struct rusage usage;
@@ -594,7 +594,7 @@ void BrowserStartupMetricRecorder::RecordFirstRunSenti
 }
 
 void BrowserStartupMetricRecorder::RecordHardFaultHistogram() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DCHECK_EQ(UNDETERMINED_STARTUP_TEMPERATURE, g_startup_temperature);
 
   const std::optional<uint32_t> hard_fault_count =
