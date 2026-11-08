--- src/ucs/sys/sys.c.orig	2026-09-12 01:59:18 UTC
+++ src/ucs/sys/sys.c
@@ -23,16 +23,29 @@
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
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
 #ifdef HAVE_SYS_THR_H
 #include <sys/thr.h>
 #endif
@@ -94,7 +107,7 @@ const char *ucs_get_host_name()
 
 const char *ucs_get_host_name()
 {
-    static char hostname[HOST_NAME_MAX] = {0};
+    static char hostname[UCS_HOST_NAME_MAX] = {0};
 
     if (*hostname == 0) {
         gethostname(hostname, sizeof(hostname));
@@ -209,6 +222,46 @@ static uint64_t ucs_get_mac_address()
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
@@ -256,6 +309,7 @@ static uint64_t ucs_get_mac_address()
     }
 
     return mac_address;
+#endif
 }
 
 static uint64_t __sumup_host_name(unsigned prime_index)
@@ -699,6 +753,22 @@ size_t ucs_get_memfree_size()
 {
     ssize_t mem_free;
 
+#if defined(__FreeBSD__)
+    unsigned long v_free_count;
+    unsigned long pagesize;
+    size_t len;
+
+    len = sizeof(v_free_count);
+    if (sysctlbyname("vm.stats.vm.v_free_count", &v_free_count, &len,
+                     NULL, 0) == 0) {
+        len = sizeof(pagesize);
+        if (sysctlbyname("hw.pagesize", &pagesize, &len, NULL, 0) == 0) {
+            return v_free_count * pagesize;
+        }
+    }
+
+    return UCS_DEFAULT_MEM_FREE;
+#else
     mem_free = ucs_get_meminfo_entry("MemFree", 1);
     if (mem_free == -1) {
         mem_free = UCS_DEFAULT_MEM_FREE;
@@ -707,12 +777,16 @@ size_t ucs_get_memfree_size()
     }
 
     return mem_free;
+#endif
 }
 
 ssize_t ucs_get_huge_page_size()
 {
     static ssize_t huge_page_size = 0;
 
+#if defined(__FreeBSD__)
+    return -1;
+#else
     /* Cache the huge page size value */
     if (huge_page_size == 0) {
         huge_page_size = ucs_get_meminfo_entry("Hugepagesize", 1);
@@ -724,6 +798,7 @@ ssize_t ucs_get_huge_page_size()
     }
 
     return huge_page_size;
+#endif
 }
 
 static ssize_t ucs_get_huge_pages_count()
@@ -777,6 +852,17 @@ size_t ucs_get_shmmax()
 #define UCS_PROC_SYS_SHMMAX_FILE "/proc/sys/kernel/shmmax"
 size_t ucs_get_shmmax()
 {
+#if defined(__FreeBSD__)
+    unsigned long shmmax;
+    size_t len = sizeof(shmmax);
+
+    if (sysctlbyname("kern.ipc.shmmax", &shmmax, &len, NULL, 0) != 0) {
+        ucs_warn("failed to read kern.ipc.shmmax: %m");
+        return 0;
+    }
+
+    return (size_t)shmmax;
+#else
     ucs_status_t status;
     long size;
 
@@ -787,12 +873,17 @@ size_t ucs_get_shmmax()
     }
 
     return size;
+#endif
 }
 
 static void ucs_sysv_shmget_error_check_ENOSPC(size_t alloc_size,
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
@@ -824,6 +915,7 @@ static void ucs_sysv_shmget_error_check_ENOSPC(size_t 
                  " limit in /proc/sys/kernel/shmall (=%lu)",
                  new_shm_tot, ipc_info->shmall);
     }
+#endif
 }
 
 ucs_status_t ucs_sys_get_proc_cap(uint32_t *effective)
@@ -884,6 +976,14 @@ static void ucs_sysv_shmget_format_error(size_t alloc_
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
@@ -921,6 +1021,7 @@ static void ucs_sysv_shmget_format_error(size_t alloc_
     if (p == errp) {
         snprintf(p, endp - p, ", please check shared memory limits by 'ipcs -l'");
     }
+#endif
 }
 
 ucs_status_t ucs_sysv_alloc(size_t *size, size_t max_size, void **address_p,
@@ -1315,11 +1416,44 @@ void *ucs_sys_realloc(void *old_ptr, size_t old_length
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
@@ -1328,7 +1462,7 @@ void *ucs_sys_realloc(void *old_ptr, size_t old_length
         }
     } else {
         old_length = ucs_align_up_pow2(old_length, ucs_get_page_size());
-        ptr = (void*)syscall(__NR_mremap, old_ptr, old_length, new_length,
+        ptr = (void*)syscall(SYS_mremap, old_ptr, old_length, new_length,
                              MREMAP_MAYMOVE);
         if (ptr == MAP_FAILED) {
             ucs_log_fatal_error("mremap(%p, %zu, %zu, MAYMOVE) failed: %m",
@@ -1338,6 +1472,13 @@ void *ucs_sys_realloc(void *old_ptr, size_t old_length
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
@@ -1345,11 +1486,19 @@ void ucs_sys_free(void *ptr, size_t length)
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
 
@@ -1419,12 +1568,32 @@ ucs_status_t ucs_sys_pthread_getaffinity(ucs_sys_cpuse
 
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
@@ -1494,6 +1663,10 @@ ucs_status_t ucs_sys_get_boot_id(uint64_t *high, uint6
 
     static ucs_init_once_t init_once = UCS_INIT_ONCE_INITIALIZER;
     static ucs_status_t status       = UCS_ERR_IO_ERROR;
+#if defined(__FreeBSD__)
+    struct timeval boottime;
+    size_t len;
+#else
     char bootid_str[256];
     ssize_t size;
     uint32_t v1;
@@ -1503,8 +1676,17 @@ ucs_status_t ucs_sys_get_boot_id(uint64_t *high, uint6
     uint8_t v5[6];
     int res;
     int i;
+#endif
 
     UCS_INIT_ONCE(&init_once) {
+#if defined(__FreeBSD__)
+        len = sizeof(boottime);
+        if (sysctlbyname("kern.boottime", &boottime, &len, NULL, 0) == 0) {
+            boot_id.high = (uint64_t)boottime.tv_sec;
+            boot_id.low  = (uint64_t)boottime.tv_usec;
+            status       = UCS_OK;
+        }
+#else
         size = ucs_read_file_str(bootid_str, sizeof(bootid_str), 1,
                                  "%s", UCS_PROCESS_BOOTID_FILE);
         if (size <= 0) {
@@ -1524,6 +1706,7 @@ ucs_status_t ucs_sys_get_boot_id(uint64_t *high, uint6
                 boot_id.high |= (uint64_t)v5[i] << (16 + (i * 8));
             }
         }
+#endif
     }
 
     if (status == UCS_OK) {
@@ -1601,7 +1784,8 @@ ucs_status_t ucs_pthread_create(pthread_t *thread_id_p
 
     ret = pthread_create(&thread_id, NULL, start_routine, arg);
     if (ret != 0) {
-        ucs_error("pthread_create() failed: %m");
+        ucs_error("pthread_create(start_routine=%p arg=%p) failed: %s (%d)",
+                  start_routine, arg, strerror(ret), ret);
         return UCS_ERR_IO_ERROR;
     }
 
@@ -1630,6 +1814,52 @@ unsigned long ucs_sys_get_proc_create_time(pid_t pid)
 
 unsigned long ucs_sys_get_proc_create_time(pid_t pid)
 {
+#if defined(__FreeBSD__)
+    struct kinfo_proc kp;
+    struct timeval boottime;
+    uint64_t proc_usec, boot_usec, start_usec;
+    size_t len;
+    int mib[4];
+
+    /*
+     * FreeBSD exposes process creation time through struct kinfo_proc.
+     * Preserve the API semantics of returning time since system boot.
+     */
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC;
+    mib[2] = KERN_PROC_PID;
+    mib[3] = pid;
+
+    memset(&kp, 0, sizeof(kp));
+    len = sizeof(kp);
+
+    if (sysctl(mib, 4, &kp, &len, NULL, 0) < 0) {
+        ucs_debug("failed to get information for pid %d: %m", pid);
+        return 0ul;
+    }
+
+    if ((len == 0) || (kp.ki_pid != pid)) {
+        return 0ul;
+    }
+
+    len = sizeof(boottime);
+    if (sysctlbyname("kern.boottime", &boottime, &len, NULL, 0) < 0) {
+        ucs_debug("failed to get system boot time: %m");
+        return 0ul;
+    }
+
+    proc_usec = ((uint64_t)kp.ki_start.tv_sec * UCS_MBYTE) +
+                kp.ki_start.tv_usec;
+    boot_usec = ((uint64_t)boottime.tv_sec * UCS_MBYTE) +
+                boottime.tv_usec;
+
+    if (proc_usec <= boot_usec) {
+        return 0ul;
+    }
+
+    start_usec = proc_usec - boot_usec;
+    return (unsigned long)start_usec;
+#else
     char stat[1024];
     char *start_str;
     ssize_t size;
@@ -1658,6 +1888,7 @@ err:
     ucs_debug("failed to scan "UCS_PROCCESS_STAT_FMT, pid);
 err:
     return 0ul;
+#endif
 }
 
 ucs_status_t ucs_sys_get_effective_memlock_rlimit(size_t *rlimit_value)
