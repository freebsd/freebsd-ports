--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread_posix.cc.orig	2024-02-04 14:46:08 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread_posix.cc
@@ -17,7 +17,7 @@
 #include "base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread_internal_posix.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <sys/syscall.h>
 #include <atomic>
 #endif
