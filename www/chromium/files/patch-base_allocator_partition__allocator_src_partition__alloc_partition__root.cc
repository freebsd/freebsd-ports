--- base/allocator/partition_allocator/src/partition_alloc/partition_root.cc.orig	2025-07-02 06:08:04 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_root.cc
@@ -45,7 +45,7 @@
 #include "wow64apiset.h"
 #endif
 
-#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS)
+#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
 #include <pthread.h>
 #if PA_CONFIG(ENABLE_SHADOW_METADATA)
 #include <sys/mman.h>
@@ -298,7 +298,7 @@ void PartitionAllocMallocInitOnce() {
     return;
   }
 
-#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS)
+#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
   // When fork() is called, only the current thread continues to execute in the
   // child process. If the lock is held, but *not* by this thread when fork() is
   // called, we have a deadlock.
@@ -1110,7 +1110,7 @@ void PartitionRoot::Init(PartitionOptions opts) {
     // apple OSes.
     PA_CHECK((internal::SystemPageSize() == (size_t{1} << 12)) ||
              (internal::SystemPageSize() == (size_t{1} << 14)));
-#elif PA_BUILDFLAG(IS_LINUX) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)
+#elif (PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_BSD)) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)
     // Check runtime pagesize. Though the code is currently the same, it is
     // not merged with the IS_APPLE case above as a 1 << 16 case is only
     // supported on Linux on AArch64.
