--- base/allocator/partition_allocator/src/partition_alloc/thread_isolation/pkey.cc.orig	2025-09-11 13:19:19 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/thread_isolation/pkey.cc
@@ -21,7 +21,7 @@
 #include "partition_alloc/partition_alloc_check.h"
 #include "partition_alloc/thread_isolation/thread_isolation.h"
 
-#if !PA_BUILDFLAG(IS_LINUX) && !PA_BUILDFLAG(IS_CHROMEOS)
+#if !PA_BUILDFLAG(IS_LINUX) && !PA_BUILDFLAG(IS_CHROMEOS) && !PA_BUILDFLAG(IS_BSD)
 #error "This pkey code is currently only supported on Linux and ChromeOS"
 #endif
 
