--- src/3rdparty/chromium/content/browser/memory/memory_coordinator_impl.cc.orig	2017-01-26 00:49:13 UTC
+++ src/3rdparty/chromium/content/browser/memory/memory_coordinator_impl.cc
@@ -116,8 +116,12 @@ void RecordMetricsOnStateChange(base::Me
 struct MemoryCoordinatorSingletonTraits
     : public base::LeakySingletonTraits<MemoryCoordinator> {
   static MemoryCoordinator* New() {
+#if defined(OS_BSD)
+    return NULL;
+#else
     return new MemoryCoordinatorImpl(base::ThreadTaskRunnerHandle::Get(),
                                      CreateMemoryMonitor());
+#endif
   }
 };
 
