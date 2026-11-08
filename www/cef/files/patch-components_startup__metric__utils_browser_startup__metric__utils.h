--- components/startup_metric_utils/browser/startup_metric_utils.h.orig	2026-08-31 10:59:09 UTC
+++ components/startup_metric_utils/browser/startup_metric_utils.h
@@ -197,7 +197,7 @@ class COMPONENT_EXPORT(STARTUP_METRIC_UTILS)
   // Only permit construction from within GetBrowser().
   BrowserStartupMetricRecorder();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns the hard fault count of the current process, or nullopt if it can't
   // be determined.
   std::optional<uint32_t> GetHardFaultCountForCurrentProcess();
