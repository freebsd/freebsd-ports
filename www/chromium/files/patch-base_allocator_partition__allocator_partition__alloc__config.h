--- base/allocator/partition_allocator/partition_alloc_config.h.orig	2021-12-31 00:57:18 UTC
+++ base/allocator/partition_allocator/partition_alloc_config.h
@@ -59,6 +59,10 @@ static_assert(sizeof(void*) != 8, "");
 #define PA_HAS_LINUX_KERNEL
 #endif
 
+#if defined(OS_FREEBSD)
+#define PA_HAS_FREEBSD_KERNEL
+#endif
+
 // On some platforms, we implement locking by spinning in userspace, then going
 // into the kernel only if there is contention. This requires platform support,
 // namely:
@@ -73,7 +77,7 @@ static_assert(sizeof(void*) != 8, "");
 // assume that pthread_mutex_trylock() is suitable.
 //
 // Otherwise, a userspace spinlock implementation is used.
-#if defined(PA_HAS_LINUX_KERNEL) || defined(OS_WIN) || \
+#if defined(PA_HAS_LINUX_KERNEL) || defined(PA_HAS_FREEBSD_KERNEL) || defined(OS_WIN) || \
     (defined(OS_POSIX) && !defined(OS_APPLE)) || defined(OS_FUCHSIA)
 #define PA_HAS_FAST_MUTEX
 #endif
