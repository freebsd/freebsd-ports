--- lib/utils.c.orig	2016-01-08 11:43:49 UTC
+++ lib/utils.c
@@ -43,6 +43,16 @@
 
 #include <event2/util.h>
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#include <netinet/in.h>
+#include <stdlib.h>
+#include <kvm.h>
+#include <paths.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
+
 extern int inet_pton(int af, const char *src, void *dst);
 
 
@@ -1469,14 +1479,20 @@ get_argv_utf8 (int *argc)
 }
 #endif  /* ifdef WIN32 */
 
-#ifdef __linux__
+
 /* read the link of /proc/123/exe and compare with `process_name' */
 static int
-find_process_in_dirent(struct dirent *dir, const char *process_name)
+find_process_in_dirent_procfs(struct dirent *dir, const char *process_name) 
 {
     char path[512];
     /* fisrst construct a path like /proc/123/exe */
+#if defined(__linux__)
     if (sprintf (path, "/proc/%s/exe", dir->d_name) < 0) {
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
+    if (sprintf (path, "/proc/%s/file", dir->d_name) < 0) {
+#else
+    if (1) {
+#endif
         return -1;
     }
 
@@ -1500,7 +1516,8 @@ find_process_in_dirent(struct dirent *di
 }
 
 /* read the /proc fs to determine whether some process is running */
-gboolean process_is_running (const char *process_name)
+static gboolean 
+process_is_running_procfs (const char *process_name)
 {
     DIR *proc_dir = opendir("/proc");
     if (!proc_dir) {
@@ -1514,7 +1531,7 @@ gboolean process_is_running (const char 
         /* /proc/[1-9][0-9]* */
         if (first > '9' || first < '1')
             continue;
-        int pid = find_process_in_dirent(subdir, process_name);
+        int pid = find_process_in_dirent_procfs(subdir, process_name);
         if (pid > 0) {
             closedir(proc_dir);
             return TRUE;
@@ -1524,6 +1541,18 @@ gboolean process_is_running (const char 
     closedir(proc_dir);
     return FALSE;
 }
+
+#ifdef __linux__
+static int
+find_process_in_dirent(struct dirent *dir, const char *process_name)
+{
+    return find_process_in_dirent_procfs(dir, process_name);
+}
+
+gboolean 
+process_is_running (const char *process_name) {
+    return process_is_running_procfs(process_name);
+}
 #endif
 
 #ifdef __APPLE__
@@ -1534,6 +1563,113 @@ gboolean process_is_running (const char 
 }
 #endif
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__)
+#if __FreeBSD_version < 1100097
+#define PSKIP(kp) ((kp)->ki_pid == mypid ||               \
+                   (!kthreads && ((kp)->ki_flag & P_KTHREAD) != 0))
+#else
+#define PSKIP(kp) ((kp)->ki_pid == mypid ||               \
+                   (!kthreads && ((kp)->ki_flag & P_KPROC) != 0))
+#endif
+#define KVM_OPENFILES(exec, coref, buf) \
+		kvm_openfiles(exec, coref, NULL, O_RDONLY, buf)
+#define KVM_GETPROCS(kd, plist, nproc) \
+       		kvm_getprocs(kd, KERN_PROC_PROC, 0, &nproc)
+
+#elif defined(__DragonFly__)
+#define	PSKIP(kp) ((kp)->kp_pid == mypid ||			\
+		   (!kthreads && ((kp)->kp_flags & P_SYSTEM) != 0))
+#define KVM_OPENFILES(exec, coref, buf) \
+		kvm_openfiles(exec, coref, NULL, O_RDONLY, buf)
+#define KVM_GETPROCS(kd, plist, nproc) \
+		kvm_getprocs(kd, KERN_PROC_ALL, 0, &nproc)
+
+#elif defined(__NetBSD__)
+#define	PSKIP(kp) ((kp)->kp_pid == mypid ||			\
+		   ((kp)->p_flag & P_SYSTEM) != 0)
+#define KVM_OPENFILES(exec, coref, buf) \
+		kvm_openfiles(exec, coref, NULL, KVM_NO_FILES, buf)
+#define KVM_GETPROCS(kd, plist, nproc) \
+		kvm_getprocs(kd, KERN_PROC_ALL, 0, sizeof(*plist), &nproc)
+
+#elif defined(__OpenBSD__)
+#define	PSKIP(kp) ((kp)->kp_pid == mypid ||			\
+		   ((kp)->p_flag & (P_SYSTEM | P_THREAD)) != 0)
+#define KVM_OPENFILES(exec, coref, buf) \
+		kvm_openfiles(exec, coref, NULL, KVM_NO_FILES, buf)
+#define KVM_GETPROCS(kd, plist, nproc) \
+		kvm_getprocs(kd, KERN_PROC_ALL, 0, sizeof(*plist), &nproc)
+
+#else
+#define PSKIP(kp) 0
+#define KVM_OPENFILES(exec, coref, buf) 0
+#define KVM_GETPROCS(kd, plist, nproc) 0
+#endif
+
+#define WITH_PROC_FS g_file_test("/proc/curproc", G_FILE_TEST_EXISTS)
+
+static int 
+count_running_process_kvm(const char *process_name) {
+    
+    static kvm_t    *kd;
+    static struct    kinfo_proc *plist;
+    static int    nproc;
+    static pid_t    mypid;
+    static int      kthreads;
+
+    char buf[_POSIX2_LINE_MAX]; 
+    const char * execf, *coref;
+    char **pargv;
+    int i, selected_nproc;
+    struct kinfo_proc *kp;
+
+    selected_nproc = 0;
+    execf = NULL;
+    coref = _PATH_DEVNULL;
+    
+    mypid = getpid();
+    kd = KVM_OPENFILES(execf, coref, buf);
+    if (kd == NULL) {
+        fprintf(stderr, "Error: Cannot open kernel files (%s)", buf);
+        exit(1);
+    }
+
+    plist = KVM_GETPROCS(kd, plist, nproc);
+    if (plist == NULL) {
+        fprintf(stderr, "Error: Cannot get process list (%s)", kvm_geterr(kd));
+        exit(1);
+    }
+
+    for(i = 0, kp = plist; i < nproc; i++, kp++) {
+        if (PSKIP(kp)) {
+            continue;
+        }
+        if ((pargv = kvm_getargv(kd, kp, 0)) != NULL) {
+            if (strstr(pargv[0], process_name) != NULL) {
+                selected_nproc += 1;
+            }
+        }
+    }
+    kvm_close(kd);
+    kvm_close(kd);
+
+    return selected_nproc;
+}
+
+gboolean
+process_is_running(const char * process_name) {
+    if (WITH_PROC_FS) { 
+        return process_is_running_procfs(process_name);
+    }
+    if (count_running_process_kvm(process_name) > 0) {
+        return TRUE;
+    } else {
+        return FALSE;
+    }
+}
+#endif
+
 char*
 ccnet_object_type_from_id (const char *object_id)
 {
