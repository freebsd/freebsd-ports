--- base/allocator/partition_allocator/partition_root.cc.orig	2021-04-15 11:28:02 UTC
+++ base/allocator/partition_allocator/partition_root.cc
@@ -20,7 +20,7 @@
 #include "wow64apiset.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <pthread.h>
 #endif
 
@@ -34,7 +34,7 @@ namespace {
 
 #if BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 // NO_THREAD_SAFETY_ANALYSIS: acquires the lock and doesn't release it, by
 // design.
@@ -87,7 +87,7 @@ void AfterForkInChild() {
   internal::ThreadCacheRegistry::Instance()
       .ForcePurgeAllThreadAfterForkUnsafe();
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 std::atomic<bool> g_global_init_called;
 void PartitionAllocMallocInitOnce() {
@@ -97,7 +97,7 @@ void PartitionAllocMallocInitOnce() {
   if (!g_global_init_called.compare_exchange_strong(expected, true))
     return;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // When fork() is called, only the current thread continues to execute in the
   // child process. If the lock is held, but *not* by this thread when fork() is
   // called, we have a deadlock.
@@ -122,7 +122,7 @@ void PartitionAllocMallocInitOnce() {
   int err =
       pthread_atfork(BeforeForkInParent, AfterForkInParent, AfterForkInChild);
   PA_CHECK(err == 0);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 #endif  // BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
 
