--- content/browser/memory/memory_coordinator_impl.cc.orig	2017-03-09 20:04:32 UTC
+++ content/browser/memory/memory_coordinator_impl.cc
@@ -148,8 +148,12 @@ void MemoryCoordinatorHandleImpl::AddChi
 struct MemoryCoordinatorImplSingletonTraits
     : public base::LeakySingletonTraits<MemoryCoordinatorImpl> {
   static MemoryCoordinatorImpl* New() {
+#if defined(OS_BSD)
+    return nullptr;
+#else
     return new MemoryCoordinatorImpl(base::ThreadTaskRunnerHandle::Get(),
                                      CreateMemoryMonitor());
+#endif
   }
 };
 
