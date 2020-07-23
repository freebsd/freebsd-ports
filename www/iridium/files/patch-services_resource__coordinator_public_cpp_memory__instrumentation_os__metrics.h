--- services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h.orig	2019-07-24 18:58:35 UTC
+++ services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h
@@ -28,9 +28,9 @@ class COMPONENT_EXPORT(
                                     mojom::RawOSMemDump*);
   static std::vector<mojom::VmRegionPtr> GetProcessMemoryMaps(base::ProcessId);
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   static void SetProcSmapsForTesting(FILE*);
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
  private:
   FRIEND_TEST_ALL_PREFIXES(OSMetricsTest, ParseProcSmaps);
@@ -44,7 +44,7 @@ class COMPONENT_EXPORT(
   static std::vector<mojom::VmRegionPtr> GetProcessModules(base::ProcessId);
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Provides information on the dump state of resident pages.
   enum class MappedAndResidentPagesDumpState {
     // Access to /proc/<pid>/pagemap can be denied for android devices running
@@ -68,7 +68,7 @@ class COMPONENT_EXPORT(
   // TODO(chiniforooshan): move to /base/process/process_metrics_linux.cc after
   // making sure that peak RSS is useful.
   static size_t GetPeakResidentSetSize(base::ProcessId pid);
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 };
 
 }  // namespace memory_instrumentation
