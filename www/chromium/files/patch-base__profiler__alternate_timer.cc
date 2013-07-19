--- base/profiler/alternate_timer.cc	2013-07-03 23:39:54.000000000 -0400
+++ base/profiler/alternate_timer.cc	2013-07-19 00:41:06.000000000 -0400
@@ -21,7 +21,7 @@
 // Set an alternate timer function to replace the OS time function when
 // profiling.
 void SetAlternateTimeSource(NowFunction* now_function, TimeSourceType type) {
-  DCHECK_EQ(reinterpret_cast<NowFunction*>(NULL), g_time_function);
+  DCHECK_EQ(static_cast<NowFunction*>(0), g_time_function);
   g_time_function = now_function;
   g_time_source_type = type;
 }
