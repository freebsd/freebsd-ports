--- third_party/partition_alloc/src/partition_alloc/partition_alloc_base/debug/proc_maps_linux.cc.orig	1970-01-01 00:00:00 UTC
+++ third_party/partition_alloc/src/partition_alloc/partition_alloc_base/debug/proc_maps_linux.cc
@@ -15,7 +15,7 @@
 #include "partition_alloc/partition_alloc_check.h"
 
 #if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || \
-    PA_BUILDFLAG(IS_ANDROID)
+    PA_BUILDFLAG(IS_ANDROID) || PA_BUILDFLAG(IS_BSD)
 #include <inttypes.h>
 #endif
 
