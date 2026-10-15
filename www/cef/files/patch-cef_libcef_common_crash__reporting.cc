--- cef/libcef/common/crash_reporting.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/common/crash_reporting.cc
@@ -125,7 +125,10 @@ void InitCrashReporter(const base::Comma
   }
 
   g_crash_reporting_enabled = true;
-#else   // !BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_BSD)
+  // Crashpad does not support BSD, so crash reporting is not available.
+  LOG(WARNING) << "Crash reporting is not supported on this platform";
+#else   // !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   if (process_type != switches::kZygoteProcess) {
     // Crash reporting for subprocesses created using the zygote will be
     // initialized in ZygoteForked.
