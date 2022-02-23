--- base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2022-02-23 16:08:07 UTC
+++ base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -339,8 +339,12 @@ bool TryRecommitSystemPagesInternal(
 }
 
 void DiscardSystemPagesInternal(void* address, size_t length) {
-#if defined(OS_APPLE)
+#if defined(OS_APPLE) || defined(OS_BSD)
+#if defined(OS_BSD)
+  int ret = madvise(address, length, MADV_FREE);
+#else
   int ret = madvise(address, length, MADV_FREE_REUSABLE);
+#endif
   if (ret) {
     // MADV_FREE_REUSABLE sometimes fails, so fall back to MADV_DONTNEED.
     ret = madvise(address, length, MADV_DONTNEED);
