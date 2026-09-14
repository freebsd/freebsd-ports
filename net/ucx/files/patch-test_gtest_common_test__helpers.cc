--- test/gtest/common/test_helpers.cc.orig	2026-09-09 16:59:33 UTC
+++ test/gtest/common/test_helpers.cc
@@ -14,8 +14,18 @@
 #include <ucs/config/parser.h>
 
 #include <unistd.h>
+#include <signal.h>
+#include <sys/wait.h>
 #include <sstream>
 
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/queue.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#include <libprocstat.h>
+#endif
+
 extern "C" {
 // On some platforms users have to declare environ explicitly
 extern char** environ;
@@ -504,7 +514,7 @@ std::vector<std::string> read_dir(const std::string &p
 
     dir = opendir(path.c_str());
     if (dir == NULL) {
-        goto out_close;
+        return result;
     }
 
     for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
@@ -513,7 +523,6 @@ std::vector<std::string> read_dir(const std::string &p
         }
     }
 
-out_close:
     closedir(dir);
     return result;
 }
@@ -521,6 +530,42 @@ std::set<int> get_open_fds()
 std::set<int> get_open_fds()
 {
     std::set<int> fds;
+
+#if defined(__FreeBSD__)
+    struct procstat *procstat;
+    struct kinfo_proc *procs;
+    struct filestat_list *files;
+    struct filestat *fst;
+    unsigned int count;
+
+    procstat = procstat_open_sysctl();
+    if (procstat == NULL) {
+        ucs_fatal("procstat_open_sysctl() failed");
+    }
+
+    procs = procstat_getprocs(procstat, KERN_PROC_PID, getpid(), &count);
+    if ((procs == NULL) || (count == 0)) {
+        procstat_close(procstat);
+        ucs_fatal("procstat_getprocs() failed");
+    }
+
+    files = procstat_getfiles(procstat, &procs[0], 0);
+    if (files == NULL) {
+        procstat_freeprocs(procstat, procs);
+        procstat_close(procstat);
+        ucs_fatal("procstat_getfiles() failed");
+    }
+
+    STAILQ_FOREACH(fst, files, next) {
+        if (fst->fs_fd >= 0) {
+            fds.insert(fst->fs_fd);
+        }
+    }
+
+    procstat_freefiles(procstat, files);
+    procstat_freeprocs(procstat, procs);
+    procstat_close(procstat);
+#else
     DIR *dir = opendir("/proc/self/fd");
     if (dir == NULL) {
         ucs_fatal("failed to open /proc/self/fd");
@@ -542,11 +587,54 @@ std::set<int> get_open_fds()
         }
     }
     closedir(dir);
+#endif
+
     return fds;
 }
 
 std::string readlink_proc_fd(int fd)
 {
+#if defined(__FreeBSD__)
+    struct procstat *procstat;
+    struct kinfo_proc *procs;
+    struct filestat_list *files;
+    struct filestat *fst;
+    unsigned int count;
+    std::string result("<unknown>");
+
+    procstat = procstat_open_sysctl();
+    if (procstat == NULL) {
+        return "<procstat_open_sysctl failed>";
+    }
+
+    procs = procstat_getprocs(procstat, KERN_PROC_PID, getpid(), &count);
+    if ((procs == NULL) || (count == 0)) {
+        procstat_close(procstat);
+        return "<procstat_getprocs failed>";
+    }
+
+    files = procstat_getfiles(procstat, &procs[0], 0);
+    if (files == NULL) {
+        procstat_freeprocs(procstat, procs);
+        procstat_close(procstat);
+        return "<procstat_getfiles failed>";
+    }
+
+    STAILQ_FOREACH(fst, files, next) {
+        if (fst->fs_fd == fd) {
+            if ((fst->fs_path != NULL) && (fst->fs_path[0] != '\0')) {
+                result = fst->fs_path;
+            }
+            break;
+        }
+    }
+
+    procstat_freefiles(procstat, files);
+    procstat_freeprocs(procstat, procs);
+    procstat_close(procstat);
+
+    return result;
+#else
     char path[64], link[PATH_MAX];
     const size_t max_len = sizeof(link) - 1;
 
@@ -559,6 +647,7 @@ std::string readlink_proc_fd(int fd)
 
     link[len] = '\0';
     return std::string(link);
+#endif
 }
 
 static std::map<std::string, std::string> get_all_rdmacm_net_devices()
