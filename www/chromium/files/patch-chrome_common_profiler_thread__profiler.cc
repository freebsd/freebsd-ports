--- chrome/common/profiler/thread_profiler.cc.orig	2021-04-23 13:14:22 UTC
+++ chrome/common/profiler/thread_profiler.cc
@@ -58,6 +58,9 @@ ThreadProfiler* g_main_thread_instance = nullptr;
 constexpr double kFractionOfExecutionTimeToSample = 0.02;
 
 bool IsCurrentProcessBackgrounded() {
+#if defined(OS_BSD)
+  return false;
+#else
 #if defined(OS_MAC)
   // Port provider that returns the calling process's task port, ignoring its
   // argument.
@@ -71,6 +74,7 @@ bool IsCurrentProcessBackgrounded() {
 #else   // defined(OS_MAC)
   return base::Process::Current().IsProcessBackgrounded();
 #endif  // defined(OS_MAC)
+#endif
 }
 
 #if defined(OS_ANDROID) && BUILDFLAG(ENABLE_ARM_CFI_TABLE)
