--- src/chrome/browser/browser_process_impl.h.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/browser_process_impl.h
@@ -443,7 +443,7 @@ class BrowserProcessImpl : public Browse
 
   std::unique_ptr<BatteryMetrics> battery_metrics_;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::RepeatingTimer autoupdate_timer_;
 
   // Gets called by autoupdate timer to see if browser needs restart and can be
