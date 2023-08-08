--- src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc_base/threading/platform_thread_posix.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc_base/threading/platform_thread_posix.cc
@@ -17,7 +17,7 @@
 #include "base/allocator/partition_allocator/partition_alloc_base/threading/platform_thread_internal_posix.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <sys/syscall.h>
 #include <atomic>
 #endif
