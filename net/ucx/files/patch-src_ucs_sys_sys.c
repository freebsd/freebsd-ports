--- src/ucs/sys/sys.c.orig	2026-02-05 12:41:56 UTC
+++ src/ucs/sys/sys.c
@@ -23,16 +23,27 @@
 #include <ucm/util/sys.h>
 
 #include <unistd.h>
+#include <limits.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
 #include <sys/shm.h>
 #include <sys/mman.h>
 #include <sys/types.h>
 #include <sys/resource.h>
+#include <netinet/in.h>
 #include <net/if.h>
+#include <pthread.h>
 #include <dirent.h>
 #include <sched.h>
 #include <ctype.h>
+#include <sys/syscall.h>
+#if defined(__FreeBSD__)
+#include <ifaddrs.h>
+#include <net/if_dl.h>
+#include <net/if_types.h>
+#include <sys/param.h>
+#include <sys/cpuset.h>
+#endif
 #ifdef HAVE_SYS_THR_H
 #include <sys/thr.h>
 #endif
@@ -94,7 +105,7 @@ const char *ucs_get_host_name()
 
 const char *ucs_get_host_name()
 {
-    static char hostname[HOST_NAME_MAX] = {0};
+    static char hostname[UCS_HOST_NAME_MAX] = {0};
 
     if (*hostname == 0) {
         gethostname(hostname, sizeof(hostname));
@@ -180,6 +191,41 @@ int ucs_netif_is_ipoib(const char *if_name)
 
 int ucs_netif_is_ipoib(const char *if_name)
 {
+#if defined(__FreeBSD__)
+    struct ifaddrs *ifap = NULL, *ifa;
+    int is_ipoib = 0;
+
+    if (getifaddrs(&ifap) != 0) {
+        ucs_debug("getifaddrs() failed for %s: %m", if_name);
+        return 0;
+    }
+
+    for (ifa = ifap; ifa != NULL; ifa = ifa->ifa_next) {
+        const struct sockaddr *sa = ifa->ifa_addr;
+        const struct sockaddr_dl *sdl;
+
+        if ((ifa->ifa_name == NULL) || (sa == NULL)) {
+            continue;
+        }
+        if (strcmp(ifa->ifa_name, if_name) != 0) {
+            continue;
+        }
+        if (sa->sa_family != AF_LINK) {
+            continue;
+        }
+
+        sdl = (const struct sockaddr_dl *)sa;
+#ifdef IFT_INFINIBAND
+        if (sdl->sdl_type == IFT_INFINIBAND) {
+            is_ipoib = 1;
+            break;
+        }
+#endif
+    }
+
+    freeifaddrs(ifap);
+    return is_ipoib;
+#else
     struct ifreq ifr;
     ucs_status_t status;
 
@@ -191,11 +237,56 @@ int ucs_netif_is_ipoib(const char *if_name)
     }
 
     return ifr.ifr_hwaddr.sa_family == ARPHRD_INFINIBAND;
+#endif
 }
 
 static uint64_t ucs_get_mac_address()
 {
     static uint64_t mac_address = 0;
+#if defined(__FreeBSD__)
+    struct ifaddrs *ifap = NULL, *ifa;
+
+    if (mac_address != 0) {
+        return mac_address;
+    }
+
+    if (getifaddrs(&ifap) != 0) {
+        ucs_error("getifaddrs() failed: %m");
+        return 0;
+    }
+
+    for (ifa = ifap; ifa != NULL; ifa = ifa->ifa_next) {
+        const struct sockaddr *sa = ifa->ifa_addr;
+        const struct sockaddr_dl *sdl;
+        const unsigned char *lladdr;
+
+        if ((ifa->ifa_flags & IFF_LOOPBACK) || (sa == NULL)) {
+            continue;
+        }
+        if (sa->sa_family != AF_LINK) {
+            continue;
+        }
+
+        sdl = (const struct sockaddr_dl *)sa;
+        if (sdl->sdl_alen < 6) {
+            continue;
+        }
+
+        lladdr = (const unsigned char *)LLADDR(sdl);
+        /*
+         * Copy first 6 bytes (MAC). Keep same semantics as Linux code:
+         * store into low bytes of uint64_t.
+         */
+        mac_address = 0;
+        memcpy(&mac_address, lladdr, 6);
+        break;
+    }
+
+    freeifaddrs(ifap);
+
+    ucs_trace("MAC address is 0x%012"PRIX64, mac_address);
+    return mac_address;
+#else
     struct ifreq ifr, *it, *end;
     struct ifconf ifc;
     char buf[1024];
@@ -243,6 +334,7 @@ static uint64_t ucs_get_mac_address()
     }
 
     return mac_address;
+#endif
 }
 
 static uint64_t __sumup_host_name(unsigned prime_index)
@@ -766,6 +858,10 @@ static void ucs_sysv_shmget_error_check_ENOSPC(size_t 
                                                const struct shminfo *ipc_info,
                                                char *buf, size_t max)
 {
+#if defined(__FreeBSD__)
+    (void)alloc_size; (void)ipc_info; (void)buf; (void)max;
+    return;
+#else
     unsigned long new_used_ids;
     unsigned long new_shm_tot;
     struct shm_info shm_info;
@@ -797,6 +893,7 @@ static void ucs_sysv_shmget_error_check_ENOSPC(size_t 
                  " limit in /proc/sys/kernel/shmall (=%lu)",
                  new_shm_tot, ipc_info->shmall);
     }
+#endif
 }
 
 ucs_status_t ucs_sys_get_proc_cap(uint32_t *effective)
@@ -857,6 +954,14 @@ static void ucs_sysv_shmget_format_error(size_t alloc_
                                          const char *alloc_name, int sys_errno,
                                          char *buf, size_t max)
 {
+#if defined(__FreeBSD__)
+    /* FreeBSD does not have Linux shmctl(IPC_INFO/SHM_INFO) or struct shminfo. */
+    snprintf(buf, max,
+             "shmget(size=%zu flags=0x%x) for %s failed: %s, please check shared "
+             "memory limits by 'sysctl kern.ipc' / 'sysctl hw.pagesize' / 'ipcs -a'",
+             alloc_size, flags, alloc_name, strerror(sys_errno));
+    return;
+#else
     struct shminfo ipc_info;
     char *p, *endp, *errp;
     int ret;
@@ -894,6 +999,7 @@ static void ucs_sysv_shmget_format_error(size_t alloc_
     if (p == errp) {
         snprintf(p, endp - p, ", please check shared memory limits by 'ipcs -l'");
     }
+#endif
 }
 
 ucs_status_t ucs_sysv_alloc(size_t *size, size_t max_size, void **address_p,
@@ -1287,11 +1393,44 @@ void *ucs_sys_realloc(void *old_ptr, size_t old_length
 {
     void *ptr;
 
+#if defined(__FreeBSD__)
+    size_t copy_length;
+
     new_length = ucs_align_up_pow2(new_length, ucs_get_page_size());
     if (old_ptr == NULL) {
+        ptr = mmap(NULL, new_length, PROT_READ | PROT_WRITE,
+                   MAP_PRIVATE | MAP_ANON, -1, 0);
+        if (ptr == MAP_FAILED) {
+            ucs_log_fatal_error("mmap(NULL, %zu, READ|WRITE, PRIVATE|ANON) failed: %m",
+                                new_length);
+            return NULL;
+        }
+        return ptr;
+    }
+
+    old_length = ucs_align_up_pow2(old_length, ucs_get_page_size());
+    ptr = mmap(NULL, new_length, PROT_READ | PROT_WRITE,
+               MAP_PRIVATE | MAP_ANON, -1, 0);
+    if (ptr == MAP_FAILED) {
+        ucs_log_fatal_error("mmap(NULL, %zu, READ|WRITE, PRIVATE|ANON) failed: %m",
+                            new_length);
+        return NULL;
+    }
+
+    copy_length = ucs_min(old_length, new_length);
+    memcpy(ptr, old_ptr, copy_length);
+
+    if (munmap(old_ptr, old_length) != 0) {
+        ucs_log_fatal_error("munmap(%p, %zu) failed: %m", old_ptr, old_length);
+    }
+
+    return ptr;
+#elif defined(__linux__)
+    new_length = ucs_align_up_pow2(new_length, ucs_get_page_size());
+    if (old_ptr == NULL) {
         /* Note: Must pass the 0 offset as "long", otherwise it will be
          * partially undefined when converted to syscall arguments */
-        ptr = (void*)syscall(__NR_mmap, NULL, new_length, PROT_READ|PROT_WRITE,
+        ptr = (void*)syscall(SYS_mmap, NULL, new_length, PROT_READ|PROT_WRITE,
                              MAP_PRIVATE|MAP_ANONYMOUS, -1, 0ul);
         if (ptr == MAP_FAILED) {
             ucs_log_fatal_error("mmap(NULL, %zu, READ|WRITE, PRIVATE|ANON) failed: %m",
@@ -1300,7 +1439,7 @@ void *ucs_sys_realloc(void *old_ptr, size_t old_length
         }
     } else {
         old_length = ucs_align_up_pow2(old_length, ucs_get_page_size());
-        ptr = (void*)syscall(__NR_mremap, old_ptr, old_length, new_length,
+        ptr = (void*)syscall(SYS_mremap, old_ptr, old_length, new_length,
                              MREMAP_MAYMOVE);
         if (ptr == MAP_FAILED) {
             ucs_log_fatal_error("mremap(%p, %zu, %zu, MAYMOVE) failed: %m",
@@ -1310,6 +1449,13 @@ void *ucs_sys_realloc(void *old_ptr, size_t old_length
     }
 
     return ptr;
+#else
+(void)old_ptr;
+    (void)old_length;
+    (void)new_length;
+    ucs_log_fatal_error("ucs_sys_realloc() is not implemented on this platform");
+    return NULL;
+#endif
 }
 
 void ucs_sys_free(void *ptr, size_t length)
@@ -1317,11 +1463,19 @@ void ucs_sys_free(void *ptr, size_t length)
     int ret;
 
     if (ptr != NULL) {
+#if defined(__FreeBSD__)
         length = ucs_align_up_pow2(length, ucs_get_page_size());
-        ret = syscall(__NR_munmap, ptr, length);
+        ret = munmap(ptr, length);
         if (ret) {
             ucs_log_fatal_error("munmap(%p, %zu) failed: %m", ptr, length);
         }
+#else
+        length = ucs_align_up_pow2(length, ucs_get_page_size());
+        ret = syscall(SYS_munmap, ptr, length);
+        if (ret) {
+            ucs_log_fatal_error("munmap(%p, %zu) failed: %m", ptr, length);
+        }
+#endif
     }
 }
 
@@ -1391,12 +1545,32 @@ ucs_status_t ucs_sys_pthread_getaffinity(ucs_sys_cpuse
 
 ucs_status_t ucs_sys_pthread_getaffinity(ucs_sys_cpuset_t *cpuset)
 {
+#if defined(__FreeBSD__)
+    long tid;
+    int ret;
+
+#ifdef HAVE_SYS_THR_H
+    thr_self(&tid);
+#else
+    /* Fallback: best-effort use process id */
+    tid = (long)getpid();
+#endif
+
+    ret = cpuset_getaffinity(CPU_LEVEL_WHICH, CPU_WHICH_TID, tid,
+                             sizeof(*cpuset), cpuset);
+    if (ret != 0) {
+        ucs_error("cpuset_getaffinity(TID=%ld) failed: %m", tid);
+        return UCS_ERR_INVALID_PARAM;
+    }
+    return UCS_OK;
+#else
     if (pthread_getaffinity_np(pthread_self(), sizeof(*cpuset), cpuset)) {
         ucs_error("pthread_getaffinity_np() failed: %m");
         return UCS_ERR_INVALID_PARAM;
     }
 
     return UCS_OK;
+#endif
 }
 
 void ucs_sys_cpuset_copy(ucs_cpu_set_t *dst, const ucs_sys_cpuset_t *src)
@@ -1557,7 +1731,8 @@ ucs_status_t ucs_pthread_create(pthread_t *thread_id_p
 
     ret = pthread_create(&thread_id, NULL, start_routine, arg);
     if (ret != 0) {
-        ucs_error("pthread_create() failed: %m");
+        ucs_error("pthread_create(start_routine=%p arg=%p) failed: %s (%d)",
+                  start_routine, arg, strerror(ret), ret);
         return UCS_ERR_IO_ERROR;
     }
 
