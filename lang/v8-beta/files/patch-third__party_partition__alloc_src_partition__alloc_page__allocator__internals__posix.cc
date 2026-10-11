--- third_party/partition_alloc/src/partition_alloc/page_allocator_internals_posix.cc.orig	2026-09-18 16:27:42 UTC
+++ third_party/partition_alloc/src/partition_alloc/page_allocator_internals_posix.cc
@@ -12,6 +12,10 @@
 #include "partition_alloc/page_allocator.h"
 #include "partition_alloc/partition_alloc_base/notreached.h"
 
+#if PA_BUILDFLAG(IS_FREEBSD)
+#include <errno.h>
+#endif
+
 #if PA_BUILDFLAG(IS_APPLE)
 #include "partition_alloc/partition_alloc_base/apple/foundation_util.h"
 #if PA_BUILDFLAG(IS_IOS)
@@ -237,6 +241,21 @@ size_t GetZeroSegmentSizeFromOS() {
 size_t GetZeroSegmentSizeFromOS() {
   // TODO(40925855): Support larger `mmap_min_addr`.
   return 0x10000;  // 64KB
+}
+
+#elif PA_BUILDFLAG(IS_FREEBSD)
+
+size_t GetZeroSegmentSizeFromOS() {
+  // Unless security.bsd.map_at_zero is set, the first page is below the
+  // minimum address of the process' address space and mapping it fails with
+  // EINVAL. Otherwise it can be mapped, so reserve it here.
+  const size_t page_size = SystemPageSize();
+  if (mmap(nullptr, page_size, PROT_NONE, MAP_GUARD | MAP_FIXED | MAP_EXCL, -1,
+           0) != MAP_FAILED ||
+      errno == EINVAL) {
+    return page_size;
+  }
+  return 0;
 }
 
 #else
