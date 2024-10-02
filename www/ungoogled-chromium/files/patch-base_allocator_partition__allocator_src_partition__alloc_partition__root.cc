--- base/allocator/partition_allocator/src/partition_alloc/partition_root.cc.orig	2024-10-01 07:26:23 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_root.cc
@@ -43,7 +43,7 @@
 #include "wow64apiset.h"
 #endif
 
-#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS)
+#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
 #include <pthread.h>
 #endif
 
@@ -277,7 +277,7 @@ void PartitionAllocMallocInitOnce() {
     return;
   }
 
-#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS)
+#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
   // When fork() is called, only the current thread continues to execute in the
   // child process. If the lock is held, but *not* by this thread when fork() is
   // called, we have a deadlock.
@@ -1076,7 +1076,7 @@ void PartitionRoot::Init(PartitionOptions opts) {
     // apple OSes.
     PA_CHECK((internal::SystemPageSize() == (size_t{1} << 12)) ||
              (internal::SystemPageSize() == (size_t{1} << 14)));
-#elif PA_BUILDFLAG(IS_LINUX) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)
+#elif (PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_BSD)) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)
     // Check runtime pagesize. Though the code is currently the same, it is
     // not merged with the IS_APPLE case above as a 1 << 16 case is only
     // supported on Linux on AArch64.
