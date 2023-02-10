--- src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc_config.h.orig	2022-11-06 10:11:11 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc_config.h
@@ -66,7 +66,7 @@ static_assert(sizeof(void*) != 8, "");
 
 // POSIX is not only UNIX, e.g. macOS and other OSes. We do use Linux-specific
 // features such as futex(2).
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #define PA_HAS_LINUX_KERNEL
 #endif
 
@@ -186,7 +186,7 @@ constexpr bool kUseLazyCommit = false;
 
 // On these platforms, lock all the partitions before fork(), and unlock after.
 // This may be required on more platforms in the future.
-#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #define PA_HAS_ATFORK_HANDLER
 #endif
 
@@ -225,7 +225,7 @@ constexpr bool kUseLazyCommit = false;
 //
 // Also enabled on ARM64 macOS, as the 16kiB pages on this platform lead to
 // larger slot spans.
-#if BUILDFLAG(IS_LINUX) || (BUILDFLAG(IS_MAC) && defined(ARCH_CPU_ARM64))
+#if BUILDFLAG(IS_LINUX) || (BUILDFLAG(IS_MAC) && defined(ARCH_CPU_ARM64)) || BUILDFLAG(IS_BSD)
 #define PA_PREFER_SMALLER_SLOT_SPANS
 #endif  // BUILDFLAG(IS_LINUX)
 
