--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_forward.h.orig	2024-02-04 14:46:08 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_forward.h
@@ -28,9 +28,13 @@ namespace internal {
 // the second one 16. We could technically return something different for
 // malloc() and operator new(), but this would complicate things, and most of
 // our allocations are presumably coming from operator new() anyway.
+#if defined(__i386__) && defined(OS_FREEBSD)
+constexpr size_t kAlignment = 8;
+#else
 constexpr size_t kAlignment =
     std::max(alignof(max_align_t),
              static_cast<size_t>(__STDCPP_DEFAULT_NEW_ALIGNMENT__));
+#endif
 static_assert(kAlignment <= 16,
               "PartitionAlloc doesn't support a fundamental alignment larger "
               "than 16 bytes.");
