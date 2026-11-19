--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread_ref.h.orig	2026-11-19 12:25:27 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread_ref.h
@@ -48,7 +48,7 @@ class PlatformThreadRef {
 
   bool is_null() const { return id_ == 0; }
 
-#if PA_BUILDFLAG(IS_APPLE)
+#if PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_BSD)
   template <typename Hasher>
   size_t hash_value() const {
     return Hasher()(reinterpret_cast<uintptr_t>(id_));
