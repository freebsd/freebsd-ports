--- content/browser/memory/memory_coordinator_impl.cc.orig	2017-04-19 19:06:33 UTC
+++ content/browser/memory/memory_coordinator_impl.cc
@@ -90,8 +90,12 @@ void MemoryCoordinatorHandleImpl::AddChi
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
 
