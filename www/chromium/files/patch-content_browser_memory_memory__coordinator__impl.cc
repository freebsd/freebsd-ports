--- content/browser/memory/memory_coordinator_impl.cc.orig	2017-06-05 19:03:07 UTC
+++ content/browser/memory/memory_coordinator_impl.cc
@@ -138,8 +138,12 @@ void MemoryCoordinatorHandleImpl::AddChild(
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
 
