--- content/browser/memory/memory_coordinator_impl.cc.orig	2017-08-10 15:17:56.475998000 +0200
+++ content/browser/memory/memory_coordinator_impl.cc	2017-08-10 15:29:14.826033000 +0200
@@ -121,10 +121,13 @@
 MemoryCoordinatorImpl* MemoryCoordinatorImpl::GetInstance() {
   if (!base::FeatureList::IsEnabled(features::kMemoryCoordinator))
     return nullptr;
+#if !defined(OS_BSD)
   static MemoryCoordinatorImpl* instance = new MemoryCoordinatorImpl(
       base::ThreadTaskRunnerHandle::Get(), CreateMemoryMonitor());
   return instance;
+#endif
 }
+
 
 MemoryCoordinatorImpl::MemoryCoordinatorImpl(
     scoped_refptr<base::SingleThreadTaskRunner> task_runner,
