--- base/trace_event/heap_profiler_allocation_context_tracker.cc.orig	2021-12-14 11:44:55 UTC
+++ base/trace_event/heap_profiler_allocation_context_tracker.cc
@@ -30,6 +30,10 @@
 #include <sys/prctl.h>
 #endif
 
+#if defined(OS_BSD)
+#include <pthread_np.h>
+#endif
+
 namespace base {
 namespace trace_event {
 
@@ -62,13 +66,23 @@ ThreadLocalStorage::Slot& AllocationContextTrackerTLS(
 // with id. This function intentionally leaks the allocated strings since they
 // are used to tag allocations even after the thread dies.
 const char* GetAndLeakThreadName() {
-  char name[16];
+#if defined(OS_BSD)
+  constexpr size_t kBufferLen = 64;
+#else
+  constexpr size_t kBufferLen = 16;
+#endif
+  char name[kBufferLen];
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
   // If the thread name is not set, try to get it from prctl. Thread name might
   // not be set in cases where the thread started before heap profiling was
   // enabled.
   int err = prctl(PR_GET_NAME, name);
   if (!err) {
+    return strdup(name);
+  }
+#elif defined(OS_BSD)
+  pthread_get_name_np(pthread_self(), name, kBufferLen);
+  if (*name != '\0') {
     return strdup(name);
   }
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
