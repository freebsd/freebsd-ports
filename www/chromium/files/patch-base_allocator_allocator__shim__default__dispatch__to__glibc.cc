--- base/allocator/allocator_shim_default_dispatch_to_glibc.cc.orig	2016-12-01 23:02:05 UTC
+++ base/allocator/allocator_shim_default_dispatch_to_glibc.cc
@@ -3,19 +3,28 @@
 // found in the LICENSE file.
 
 #include "base/allocator/allocator_shim.h"
-
-#include <malloc.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <malloc_np.h>
 
 // This translation unit defines a default dispatch for the allocator shim which
 // routes allocations to libc functions.
-// The code here is strongly inspired from tcmalloc's libc_override_glibc.h.
+// The code here is strongly inspired from tcmalloc's override_glibc.h.
 
 extern "C" {
-void* __libc_malloc(size_t size);
-void* __libc_calloc(size_t n, size_t size);
-void* __libc_realloc(void* address, size_t size);
-void* __libc_memalign(size_t alignment, size_t size);
-void __libc_free(void* ptr);
+void* __malloc(size_t size);
+void* __calloc(size_t n, size_t size);
+void* __realloc(void* address, size_t size);
+void* __memalign(size_t alignment, size_t size) {
+  void *ret;
+  if (__posix_memalign(&ret, alignment, size) != 0) {
+      return nullptr;
+  } else {
+      return ret;
+  }
+}
+int __posix_memalign(void **ptr, size_t alignment, size_t size);
+void __free(void* ptr);
 }  // extern "C"
 
 namespace {
@@ -23,23 +32,23 @@ namespace {
 using base::allocator::AllocatorDispatch;
 
 void* GlibcMalloc(const AllocatorDispatch*, size_t size) {
-  return __libc_malloc(size);
+  return __malloc(size);
 }
 
 void* GlibcCalloc(const AllocatorDispatch*, size_t n, size_t size) {
-  return __libc_calloc(n, size);
+  return __calloc(n, size);
 }
 
 void* GlibcRealloc(const AllocatorDispatch*, void* address, size_t size) {
-  return __libc_realloc(address, size);
+  return __realloc(address, size);
 }
 
 void* GlibcMemalign(const AllocatorDispatch*, size_t alignment, size_t size) {
-  return __libc_memalign(alignment, size);
+  return __memalign(alignment, size);
 }
 
 void GlibcFree(const AllocatorDispatch*, void* address) {
-  __libc_free(address);
+  __free(address);
 }
 
 size_t GlibcGetSizeEstimate(const AllocatorDispatch*, void* address) {
