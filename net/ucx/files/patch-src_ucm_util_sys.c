--- src/ucm/util/sys.c.orig	2026-02-04 09:52:46 UTC
+++ src/ucm/util/sys.c
@@ -21,10 +21,17 @@
 #include <ucs/type/init_once.h>
 #include <ucs/sys/math.h>
 #include <ucs/sys/ptr_arith.h>
+#ifdef HAVE_LINUX_MMAN_H
 #include <linux/mman.h>
+#endif
 #include <sys/mman.h>
 #include <pthread.h>
+#ifdef __linux__
 #include <syscall.h>
+#elif defined(__FreeBSD__)
+#include <sys/syscall.h>
+#include <sys/thr.h>
+#endif
 #include <string.h>
 #include <unistd.h>
 #include <fcntl.h>
@@ -34,6 +41,24 @@
 
 #define UCM_PROC_SELF_MAPS "/proc/self/maps"
 
+#if !defined(__linux__)
+#include <errno.h>
+#include <sys/mman.h>
+
+void *ucm_orig_mremap(void *old_address, size_t old_size, size_t new_size,
+                      int flags, void *new_address)
+{
+    (void)old_address;
+    (void)old_size;
+    (void)new_size;
+    (void)flags;
+    (void)new_address;
+
+    errno = ENOSYS;
+    return MAP_FAILED;
+}
+#endif
+
 ucm_global_config_t ucm_global_opts = {
     .log_level                  = UCS_LOG_LEVEL_WARN,
     .enable_events              = 1,
@@ -136,7 +161,22 @@ void *ucm_sys_realloc(void *ptr, size_t size)
         return ptr;
     }
 
+#if defined(__linux__)
     newptr = ucm_orig_mremap(oldptr, oldsize, sys_size, MREMAP_MAYMOVE, NULL);
+#else
+    /* FreeBSD: no Linux mremap/MREMAP_MAYMOVE. Fallback: allocate+copy+unmap.
+     * If upper layers can tolerate "not supported", you can instead:
+     *   errno = ENOTSUP; return MAP_FAILED;
+     */
+    newptr = mmap(NULL, sys_size, PROT_READ | PROT_WRITE,
+                  MAP_PRIVATE | MAP_ANON, -1, 0);
+    if (newptr != MAP_FAILED) {
+        size_t copy_sz = (oldsize < sys_size) ? oldsize : sys_size;
+        memcpy(newptr, oldptr, copy_sz);
+        munmap(oldptr, oldsize);
+    }
+#endif
+
     if (newptr == MAP_FAILED) {
         ucm_error("mremap(oldptr=%p oldsize=%zu, newsize=%zu) failed: %m",
                   oldptr, oldsize, sys_size);
@@ -377,15 +417,31 @@ void *ucm_brk_syscall(void *addr)
 
 void *ucm_brk_syscall(void *addr)
 {
+#if defined(__linux__)
     /* Return type is equivalent to full pointer size */
     UCS_STATIC_ASSERT(sizeof(syscall(0)) == sizeof(void*));
-
     return (void*)syscall(SYS_brk, addr);
+#else
+    (void)addr;
+    errno = ENOSYS;
+    return NULL;
+#endif
 }
 
-pid_t ucm_get_tid()
+pid_t ucm_get_tid(void)
 {
-    return syscall(SYS_gettid);
+#if defined(__linux__)
+    return (pid_t)syscall(SYS_gettid);
+#elif defined(__FreeBSD__)
+    long tid;
+    if (thr_self(&tid) == 0) {
+        return (pid_t)tid;
+    }
+    /* fallback */
+    return (pid_t)getpid();
+#else
+    return (pid_t)getpid();
+#endif
 }
 
 void UCS_F_CTOR ucm_init()
