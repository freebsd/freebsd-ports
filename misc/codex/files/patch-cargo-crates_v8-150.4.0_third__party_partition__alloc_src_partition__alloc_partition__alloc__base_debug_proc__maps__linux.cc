--- cargo-crates/v8-150.4.0/third_party/partition_alloc/src/partition_alloc/partition_alloc_base/debug/proc_maps_linux.cc.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-150.4.0/third_party/partition_alloc/src/partition_alloc/partition_alloc_base/debug/proc_maps_linux.cc
@@ -15,7 +15,7 @@
 #include "partition_alloc/partition_alloc_check.h"
 
 #if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || \
-    PA_BUILDFLAG(IS_ANDROID)
+    PA_BUILDFLAG(IS_ANDROID) || PA_BUILDFLAG(IS_BSD)
 #include <inttypes.h>
 #endif
 
