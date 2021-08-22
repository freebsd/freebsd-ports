--- base/allocator/partition_allocator/partition_root.cc.orig	2021-07-19 18:45:05 UTC
+++ base/allocator/partition_allocator/partition_root.cc
@@ -25,7 +25,7 @@
 #include "wow64apiset.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <pthread.h>
 #endif
 
@@ -39,7 +39,7 @@ namespace {
 
 #if BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 // NO_THREAD_SAFETY_ANALYSIS: acquires the lock and doesn't release it, by
 // design.
@@ -92,7 +92,7 @@ void AfterForkInChild() {
   internal::ThreadCacheRegistry::Instance()
       .ForcePurgeAllThreadAfterForkUnsafe();
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 std::atomic<bool> g_global_init_called;
 void PartitionAllocMallocInitOnce() {
@@ -102,7 +102,7 @@ void PartitionAllocMallocInitOnce() {
   if (!g_global_init_called.compare_exchange_strong(expected, true))
     return;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // When fork() is called, only the current thread continues to execute in the
   // child process. If the lock is held, but *not* by this thread when fork() is
   // called, we have a deadlock.
@@ -127,7 +127,7 @@ void PartitionAllocMallocInitOnce() {
   int err =
       pthread_atfork(BeforeForkInParent, AfterForkInParent, AfterForkInChild);
   PA_CHECK(err == 0);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 #endif  // BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
 
