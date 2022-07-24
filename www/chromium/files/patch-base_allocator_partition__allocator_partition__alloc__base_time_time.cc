--- base/allocator/partition_allocator/partition_alloc_base/time/time.cc.orig	2022-07-22 17:30:31 UTC
+++ base/allocator/partition_allocator/partition_alloc_base/time/time.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // time.h is a widely included header and its size impacts build time.
 // Try not to raise this limit unless necessary. See
 // https://chromium.googlesource.com/chromium/src/+/HEAD/docs/wmax_tokens.md
