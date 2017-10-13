--- third_party/chromium/src/base/profiler/alternate_timer.cc.orig	2017-09-12 17:53:20 UTC
+++ third_party/chromium/src/base/profiler/alternate_timer.cc
@@ -21,7 +21,7 @@ const char kAlternateProfilerTime[] = "C
 // Set an alternate timer function to replace the OS time function when
 // profiling.
 void SetAlternateTimeSource(NowFunction* now_function, TimeSourceType type) {
-  DCHECK_EQ(reinterpret_cast<NowFunction*>(NULL), g_time_function);
+  DCHECK_EQ(reinterpret_cast<NowFunction*>((void *)NULL), g_time_function);
   g_time_function = now_function;
   g_time_source_type = type;
 }
