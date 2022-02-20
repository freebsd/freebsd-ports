--- base/allocator/partition_allocator/partition_alloc_config.h.orig	2022-02-07 13:39:41 UTC
+++ base/allocator/partition_allocator/partition_alloc_config.h
@@ -59,7 +59,7 @@ static_assert(sizeof(void*) != 8, "");
 
 // POSIX is not only UNIX, e.g. macOS and other OSes. We do use Linux-specific
 // features such as futex(2).
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #define PA_HAS_LINUX_KERNEL
 #endif
 
