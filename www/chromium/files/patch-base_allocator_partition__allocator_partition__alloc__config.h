--- base/allocator/partition_allocator/partition_alloc_config.h.orig	2022-04-21 18:48:31 UTC
+++ base/allocator/partition_allocator/partition_alloc_config.h
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
 
@@ -212,7 +212,7 @@ constexpr bool kUseLazyCommit = false;
 //
 // This is intended to roll out more broadly, but only enabled on Linux for now
 // to get performance bot and real-world data pre-A/B experiment.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define PA_PREFER_SMALLER_SLOT_SPANS
 #endif  // BUILDFLAG(IS_LINUX)
 
