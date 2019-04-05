--- services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h.orig	2019-03-11 22:01:02 UTC
+++ services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h
@@ -26,9 +26,9 @@ class COMPONENT_EXPORT(
                                     mojom::RawOSMemDump*);
   static std::vector<mojom::VmRegionPtr> GetProcessMemoryMaps(base::ProcessId);
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   static void SetProcSmapsForTesting(FILE*);
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
  private:
   FRIEND_TEST_ALL_PREFIXES(OSMetricsTest, ParseProcSmaps);
