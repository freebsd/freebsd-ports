--- base/allocator/allocator_shim_default_dispatch_to_glibc.cc.orig	2021-12-14 11:44:55 UTC
+++ base/allocator/allocator_shim_default_dispatch_to_glibc.cc
@@ -10,18 +10,28 @@
 #include "base/process/memory.h"
 
 #include <dlfcn.h>
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
+void* __realloc(void* address, size_t len);
+void* __memalign(size_t alignment, size_t size) {
+  void *ret;
+  if (__posix_memalign(&ret, alignment, size) != 0) {
+    return nullptr;
+  } else {
+    return ret;
+  }
+}
+int __posix_memalign(void **ptr, size_t alignment, size_t size);
+void __free(void* ptr);
 }  // extern "C"
 
 namespace {
@@ -39,7 +49,7 @@ void* GlibcMalloc(const AllocatorDispatch*, size_t siz
   if (UNLIKELY(size >= kMaxAllowedSize))
     base::TerminateBecauseOutOfMemory(size);
 
-  return __libc_malloc(size);
+  return __malloc(size);
 }
 
 void* GlibcUncheckedMalloc(const AllocatorDispatch*,
@@ -48,7 +58,7 @@ void* GlibcUncheckedMalloc(const AllocatorDispatch*,
   if (UNLIKELY(size >= kMaxAllowedSize))
     return nullptr;
 
-  return __libc_malloc(size);
+  return __malloc(size);
 }
 
 void* GlibcCalloc(const AllocatorDispatch*,
@@ -59,7 +69,7 @@ void* GlibcCalloc(const AllocatorDispatch*,
   if (UNLIKELY(!total.IsValid() || total.ValueOrDie() >= kMaxAllowedSize))
     base::TerminateBecauseOutOfMemory(size * n);
 
-  return __libc_calloc(n, size);
+  return __calloc(n, size);
 }
 
 void* GlibcRealloc(const AllocatorDispatch*,
@@ -69,7 +79,7 @@ void* GlibcRealloc(const AllocatorDispatch*,
   if (UNLIKELY(size >= kMaxAllowedSize))
     base::TerminateBecauseOutOfMemory(size);
 
-  return __libc_realloc(address, size);
+  return __realloc(address, size);
 }
 
 void* GlibcMemalign(const AllocatorDispatch*,
@@ -79,11 +89,11 @@ void* GlibcMemalign(const AllocatorDispatch*,
   if (UNLIKELY(size >= kMaxAllowedSize))
     base::TerminateBecauseOutOfMemory(size);
 
-  return __libc_memalign(alignment, size);
+  return __memalign(alignment, size);
 }
 
 void GlibcFree(const AllocatorDispatch*, void* address, void* context) {
-  __libc_free(address);
+  __free(address);
 }
 
 NO_SANITIZE("cfi-icall")
