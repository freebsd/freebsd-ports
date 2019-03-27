--- src/3rdparty/chromium/services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h
@@ -36,7 +36,7 @@ class SERVICES_RESOURCE_COORDINATOR_PUBLIC_CPP_EXPORT 
   static std::vector<mojom::VmRegionPtr> GetProcessModules(base::ProcessId);
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   static void SetProcSmapsForTesting(FILE*);
 #endif  // defined(OS_LINUX)
 };
