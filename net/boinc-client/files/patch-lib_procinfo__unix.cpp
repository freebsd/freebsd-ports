--- lib/procinfo_unix.cpp.orig	2025-11-24 08:44:26 UTC
+++ lib/procinfo_unix.cpp
@@ -30,6 +30,16 @@
 #endif
 #endif
 
+#ifdef __FreeBSD__
+#include <errno.h>
+#include <sys/sysctl.h>
+#include <sys/time.h>       // struct clockinfo
+#include <sys/resource.h>   // CPUSTATES, CP_USER, CP_NICE, CP_SYS, CP_INTR, CP_IDLE
+#include <sys/user.h>       // struct kinfo_proc
+#include "util.h"
+#include <vector>
+#endif
+
 #include <cstdio>
 #include <string.h>
 #include <sys/param.h>
@@ -172,6 +182,65 @@ int PROC_STAT::parse(char* buf) {
 // build table of all processes in system
 //
 int procinfo_setup(PROC_MAP& pm) {
+#ifdef __FreeBSD__
+// FreeBSD-native process enumeration, replacing the /proc-based approach
+// used on Linux/Solaris. This requires no /proc mount of any kind (native
+// procfs or linprocfs) and works correctly and identically whether running
+// on bare metal or inside a jail.
+//
+    int mib[3] = { CTL_KERN, KERN_PROC, KERN_PROC_PROC };
+    size_t len;
+    std::vector<struct kinfo_proc> kprocs;
+
+    for (;;) {
+        len = 0;
+        if (sysctl(mib, 3, NULL, &len, NULL, 0) != 0) {
+            fprintf(stderr,
+                "procinfo_setup(): sysctl(KERN_PROC_PROC) size query failed\n");
+            return ERR_IO;
+        }
+        kprocs.resize((len + sizeof(struct kinfo_proc) - 1) / sizeof(struct kinfo_proc));
+        size_t buflen = kprocs.size() * sizeof(struct kinfo_proc);
+        if (sysctl(mib, 3, kprocs.data(), &buflen, NULL, 0) == 0) {
+            len = buflen;
+            break;
+        }
+        if (errno != ENOMEM) {
+            fprintf(stderr,
+                "procinfo_setup(): sysctl(KERN_PROC_PROC) failed\n");
+            return ERR_IO;
+        }
+    }
+
+    int nprocs = len / sizeof(struct kinfo_proc);
+    struct kinfo_proc* kp = kprocs.data();
+    int mypid = getpid();
+    long page_size = sysconf(_SC_PAGESIZE);
+
+    for (int i = 0; i < nprocs; i++) {
+        // Guard against a userland/kernel struct-layout mismatch
+        if (kp[i].ki_structsize != sizeof(struct kinfo_proc)) continue;
+
+        PROCINFO p;
+        p.clear();
+        p.id = kp[i].ki_pid;
+        p.parentid = kp[i].ki_ppid;
+        safe_strcpy(p.command, kp[i].ki_comm);
+        p.user_time = kp[i].ki_rusage.ru_utime.tv_sec
+            + kp[i].ki_rusage.ru_utime.tv_usec / 1e6;
+        p.kernel_time = kp[i].ki_rusage.ru_stime.tv_sec
+            + kp[i].ki_rusage.ru_stime.tv_usec / 1e6;
+        // ki_rssize is in pages; PROCINFO::working_set_size wants bytes.
+        p.working_set_size = (double)kp[i].ki_rssize * page_size;
+        // FreeBSD's rusage tracks minor+major page faults directly
+        p.page_fault_count = kp[i].ki_rusage.ru_minflt + kp[i].ki_rusage.ru_majflt;
+        // No direct per-process swap-usage accounting on FreeBSD
+        p.swap_size = 0;
+        p.is_boinc_app = (p.id == mypid || strcasestr(p.command, "boinc"));
+        p.is_low_priority = (kp[i].ki_nice >= PROCESS_IDLE_PRIORITY);
+        pm.insert(std::pair<int, PROCINFO>(p.id, p));
+    }
+#else // !__FreeBSD__
     DIR *dir;
     dirent *piddir;
     FILE* fd;
@@ -263,6 +332,7 @@ int procinfo_setup(PROC_MAP& pm) {
 #endif
     }
     closedir(dir);
+#endif
     find_children(pm);
     return 0;
 }
@@ -271,6 +341,44 @@ int procinfo_setup(PROC_MAP& pm) {
 // see https://www.baeldung.com/linux/get-cpu-usage
 //
 double total_cpu_time() {
+#ifdef __FreeBSD__
+// Host-wide (jail-transparent) CPU busy time via kern.cp_time.
+// Unlike a /proc-based per-process walk, this is a single set of
+// kernel-global tick counters covering every process on the host --
+// including sibling jails and the host's own processes. This is the
+// same source top(1) uses for its aggregate CPU line, and jails do not
+// restrict or virtualize this sysctl the way they do the process table.
+//
+    long cp_time[CPUSTATES];
+    size_t len = sizeof(cp_time);
+    static double tick_scale = 0;
+
+    if (!tick_scale) {
+        struct clockinfo ci;
+        size_t cilen = sizeof(ci);
+        if (sysctlbyname("kern.clockrate", &ci, &cilen, NULL, 0) == 0
+            && ci.stathz > 0
+        ) {
+            tick_scale = 1.0 / ci.stathz;
+        } else {
+            fprintf(stderr,
+                "total_cpu_time(): kern.clockrate/stathz unavailable, assuming 100Hz\n"
+            );
+            tick_scale = 1.0 / 100.0;
+        }
+    }
+
+    if (sysctlbyname("kern.cp_time", cp_time, &len, NULL, 0) != 0) {
+        fprintf(stderr, "total_cpu_time(): sysctl kern.cp_time failed\n");
+        return 0;
+    }
+
+    double busy_ticks = (double)(
+        cp_time[CP_USER] + cp_time[CP_NICE] + cp_time[CP_SYS] + cp_time[CP_INTR]
+    );
+    return busy_ticks * tick_scale;
+
+#else // !__FreeBSD__
     char buf[1024];
     static FILE *f=NULL;
     static double scale;
@@ -297,4 +405,5 @@ double total_cpu_time() {
         return 0;
     }
     return (user+nice)*scale;
+#endif
 }
