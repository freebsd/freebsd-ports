--- chrome/browser/browser_process_impl.h.orig	2025-09-10 13:22:16 UTC
+++ chrome/browser/browser_process_impl.h
@@ -411,7 +411,7 @@ class BrowserProcessImpl : public BrowserProcess,
 
   std::unique_ptr<BatteryMetrics> battery_metrics_;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::RepeatingTimer autoupdate_timer_;
 
   // Gets called by autoupdate timer to see if browser needs restart and can be
