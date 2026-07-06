--- src/ucs/debug/memtrack.c.orig	2026-02-04 09:52:46 UTC
+++ src/ucs/debug/memtrack.c
@@ -327,7 +327,11 @@ void *ucs_malloc(size_t size, const char *name)
 
 void *ucs_malloc(size_t size, const char *name)
 {
-    void *ptr = malloc(size);
+    void *ptr;
+#ifdef UCX_ALLOC_ALIGN
+    size = ucs_align_up_pow2(size, UCX_ALLOC_ALIGN);
+#endif
+    ptr = malloc(size);
     UCS_MEMTRACK_LOG_ZERO_SIZE_ALLOACTION(size, ptr, name);
     ucs_memtrack_allocated_internal(ptr, size, name);
     return ptr;
@@ -335,14 +339,29 @@ void *ucs_calloc(size_t nmemb, size_t size, const char
 
 void *ucs_calloc(size_t nmemb, size_t size, const char *name)
 {
-    void *ptr = calloc(nmemb, size);
+    void *ptr;
+#ifdef UCX_ALLOC_ALIGN
+    size_t total = ucs_align_up_pow2(nmemb * size, UCX_ALLOC_ALIGN);
+    ptr = malloc(total);
+    if (ptr != NULL) {
+        memset(ptr, 0, total);
+    }
+    UCS_MEMTRACK_LOG_ZERO_SIZE_ALLOACTION(total, ptr, name);
+    ucs_memtrack_allocated_internal(ptr, total, name);
+    return ptr;
+#else
+    ptr = calloc(nmemb, size);
     UCS_MEMTRACK_LOG_ZERO_SIZE_ALLOACTION(nmemb * size, ptr, name);
     ucs_memtrack_allocated_internal(ptr, nmemb * size, name);
     return ptr;
+#endif
 }
 
 void *ucs_realloc(void *ptr, size_t size, const char *name)
 {
+#ifdef UCX_ALLOC_ALIGN
+    size = ucs_align_up_pow2(size, UCX_ALLOC_ALIGN);
+#endif
     ucs_memtrack_releasing_internal(ptr);
     ptr = realloc(ptr, size);
     UCS_MEMTRACK_LOG_ZERO_SIZE_ALLOACTION(size, ptr, name);
