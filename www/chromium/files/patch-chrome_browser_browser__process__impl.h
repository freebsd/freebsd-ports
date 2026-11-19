--- chrome/browser/browser_process_impl.h.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/browser_process_impl.h
@@ -439,7 +439,7 @@ class BrowserProcessImpl : public BrowserProcess,
 
   std::unique_ptr<BatteryMetrics> battery_metrics_;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::RepeatingTimer autoupdate_timer_;
 
   // Gets called by autoupdate timer to see if browser needs restart and can be
