--- src/ucm/util/sys.c.orig	2026-02-04 09:52:46 UTC
+++ src/ucm/util/sys.c
@@ -14,6 +14,13 @@
 #  include "config.h"
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/user.h>
+#include <libutil.h>
+#include <stdlib.h>
+#endif
+
 #include <ucm/api/ucm.h>
 #include <ucm/util/log.h>
 #include <ucm/mmap/mmap.h>
@@ -21,10 +28,17 @@
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
@@ -34,6 +48,24 @@
 
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
@@ -136,7 +168,22 @@ void *ucm_sys_realloc(void *ptr, size_t size)
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
@@ -148,6 +195,35 @@ void ucm_parse_proc_self_maps(ucm_proc_maps_cb_t cb, v
 
 void ucm_parse_proc_self_maps(ucm_proc_maps_cb_t cb, void *arg)
 {
+#if defined(__FreeBSD__)
+    struct kinfo_vmentry *vmmap;
+    int count, i, prot;
+    char *path;
+    char empty_path[] = "";
+
+    vmmap = kinfo_getvmmap(getpid(), &count);
+    if (vmmap == NULL) {
+        ucm_warn("kinfo_getvmmap() failed: %m");
+        return;
+    }
+
+    for (i = 0; i < count; i++) {
+        prot = 0;
+        if (vmmap[i].kve_protection & KVME_PROT_READ)  prot |= PROT_READ;
+        if (vmmap[i].kve_protection & KVME_PROT_WRITE) prot |= PROT_WRITE;
+        if (vmmap[i].kve_protection & KVME_PROT_EXEC)  prot |= PROT_EXEC;
+
+        path = (vmmap[i].kve_path[0] != '\0') ? vmmap[i].kve_path
+                                                     : empty_path;
+        if (cb(arg, (void *)vmmap[i].kve_start,
+               vmmap[i].kve_end - vmmap[i].kve_start,
+               prot, path)) {
+            break;
+        }
+    }
+
+    free(vmmap);
+#else
     static char  *buffer         = MAP_FAILED;
     static size_t buffer_size    = 32768;
     static pthread_mutex_t lock  = PTHREAD_MUTEX_INITIALIZER;
@@ -263,6 +339,7 @@ out:
 
 out:
     pthread_mutex_unlock(&lock);
+#endif
 }
 
 typedef struct {
@@ -377,15 +454,31 @@ void *ucm_brk_syscall(void *addr)
 
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
