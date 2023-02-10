--- base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2023-02-08 09:03:45 UTC
+++ base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -371,8 +371,12 @@ bool TryRecommitSystemPagesInternal(
 void DiscardSystemPagesInternal(uintptr_t address, size_t length) {
 #if !BUILDFLAG(IS_NACL)
   void* ptr = reinterpret_cast<void*>(address);
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
+#if BUILDFLAG(IS_BSD)
+  int ret = madvise(ptr, length, MADV_FREE);
+#else
   int ret = madvise(ptr, length, MADV_FREE_REUSABLE);
+#endif
   if (ret) {
     // MADV_FREE_REUSABLE sometimes fails, so fall back to MADV_DONTNEED.
     ret = madvise(ptr, length, MADV_DONTNEED);
