--- cargo-crates/v8-150.4.0/third_party/partition_alloc/src/partition_alloc/partition_alloc_base/threading/platform_thread_posix.cc.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-150.4.0/third_party/partition_alloc/src/partition_alloc/partition_alloc_base/threading/platform_thread_posix.cc
@@ -18,7 +18,7 @@
 #include "partition_alloc/partition_alloc_base/logging.h"
 #include "partition_alloc/partition_alloc_base/threading/platform_thread_internal_posix.h"
 
-#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS)
+#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
 #include <sys/syscall.h>
 #include <atomic>
 #endif
