--- base/allocator/partition_allocator/partition_alloc_config.h.orig	2022-03-28 18:11:04 UTC
+++ base/allocator/partition_allocator/partition_alloc_config.h
@@ -59,7 +59,7 @@ static_assert(sizeof(void*) != 8, "");
 
 // POSIX is not only UNIX, e.g. macOS and other OSes. We do use Linux-specific
 // features such as futex(2).
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #define PA_HAS_LINUX_KERNEL
 #endif
 
