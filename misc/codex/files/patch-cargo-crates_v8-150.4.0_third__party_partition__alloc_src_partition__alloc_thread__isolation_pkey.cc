--- cargo-crates/v8-150.4.0/third_party/partition_alloc/src/partition_alloc/thread_isolation/pkey.cc.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-150.4.0/third_party/partition_alloc/src/partition_alloc/thread_isolation/pkey.cc
@@ -17,7 +17,7 @@
 #include "partition_alloc/partition_alloc_check.h"
 #include "partition_alloc/thread_isolation/thread_isolation.h"
 
-#if !PA_BUILDFLAG(IS_LINUX) && !PA_BUILDFLAG(IS_CHROMEOS)
+#if !PA_BUILDFLAG(IS_LINUX) && !PA_BUILDFLAG(IS_CHROMEOS) && !PA_BUILDFLAG(IS_BSD)
 #error "This pkey code is currently only supported on Linux and ChromeOS"
 #endif
 
