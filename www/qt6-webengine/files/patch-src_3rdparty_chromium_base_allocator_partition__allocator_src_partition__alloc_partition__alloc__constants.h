--- src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/partition_alloc_constants.h.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/partition_alloc_constants.h
@@ -315,7 +315,7 @@ constexpr size_t kPoolMaxSize = 1 * kGiB;
 #if PA_BUILDFLAG(IS_IOS)
 constexpr size_t kPoolMaxSize = 1 * kGiB;
 #elif PA_BUILDFLAG(IS_ANDROID) || \
-    PA_BUILDFLAG(ENABLE_POINTER_COMPRESSION)
+    PA_BUILDFLAG(ENABLE_POINTER_COMPRESSION) || PA_BUILDFLAG(IS_BSD)
 constexpr size_t kPoolMaxSize = 8 * kGiB;
 #else
 constexpr size_t kPoolMaxSize = 16 * kGiB;
@@ -399,7 +399,7 @@ PA_ALWAYS_INLINE constexpr size_t MaxDirectMapped() {
 // TODO(casey.smalley@arm.com): under 64k pages we can end up in a situation
 // where a normal slot span will be large enough to contain multiple items,
 // but the address will go over the final partition page after being aligned.
-#if PA_BUILDFLAG(IS_LINUX) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)
+#if (PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_BSD)) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)
 constexpr size_t kMaxSupportedAlignment = kSuperPageSize / 4;
 #else
 constexpr size_t kMaxSupportedAlignment = kSuperPageSize / 2;
