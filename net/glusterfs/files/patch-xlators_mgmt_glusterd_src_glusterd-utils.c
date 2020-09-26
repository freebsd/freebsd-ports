--- xlators/mgmt/glusterd/src/glusterd-utils.c.orig	2020-07-06 01:22:37 UTC
+++ xlators/mgmt/glusterd/src/glusterd-utils.c
@@ -79,6 +79,14 @@
 #include <sys/sockio.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#include <sys/param.h>
+#include <sys/queue.h>
+#include <libprocstat.h>
+#include <libutil.h>
+#endif
+
 #define NFS_PROGRAM 100003
 #define NFSV3_VERSION 3
 
@@ -6270,7 +6278,6 @@ find_compatible_brick(glusterd_conf_t *conf, glusterd_
 int
 glusterd_get_sock_from_brick_pid(int pid, char *sockpath, size_t len)
 {
-    char fname[128] = "";
     char buf[1024] = "";
     char cmdline[2048] = "";
     xlator_t *this = NULL;
@@ -6285,6 +6292,22 @@ glusterd_get_sock_from_brick_pid(int pid, char *sockpa
     this = THIS;
     GF_ASSERT(this);
 
+#ifdef __FreeBSD__
+	blen = sizeof(buf);
+	int mib[4];
+
+	mib[0] = CTL_KERN;
+	mib[1] = KERN_PROC;
+	mib[2] = KERN_PROC_ARGS;
+	mib[3] = pid;
+
+    if (sys_sysctl(mib, 4, buf, &blen, NULL, blen) != 0) {
+        gf_log(this->name, GF_LOG_ERROR, "brick process %d is not running",
+               pid);
+        return ret;
+    }
+#else
+    char fname[128] = "";
     snprintf(fname, sizeof(fname), "/proc/%d/cmdline", pid);
 
     if (sys_access(fname, R_OK) != 0) {
@@ -6301,6 +6324,7 @@ glusterd_get_sock_from_brick_pid(int pid, char *sockpa
                strerror(errno), fname);
         return ret;
     }
+#endif
 
     /* convert cmdline to single string */
     for (i = 0, j = 0; i < blen; i++) {
@@ -6349,6 +6373,42 @@ glusterd_get_sock_from_brick_pid(int pid, char *sockpa
 char *
 search_brick_path_from_proc(pid_t brick_pid, char *brickpath)
 {
+    char *brick_path = NULL;
+#ifdef __FreeBSD__
+	struct filestat *fst;
+	struct procstat *ps;
+	struct kinfo_proc *kp;
+	struct filestat_list *head;
+
+	ps = procstat_open_sysctl();	
+	if (ps == NULL)
+		goto out;
+	
+	kp = kinfo_getproc(brick_pid);
+	if (kp == NULL)
+		goto out;
+	
+	head = procstat_getfiles(ps, (void *)kp, 0);
+	if (head == NULL)
+		goto out;
+
+	STAILQ_FOREACH(fst, head, next) {
+		if(fst->fs_fd < 0)
+			continue;
+
+        if (!strcmp(fst->fs_path, brickpath)) {
+            brick_path = gf_strdup(fst->fs_path);
+            break;
+        }
+	}
+
+out:
+	if (head != NULL)
+		procstat_freefiles(ps, head);
+	if (kp != NULL)
+		free(kp);
+	procstat_close(ps);
+#else
     struct dirent *dp = NULL;
     DIR *dirp = NULL;
     size_t len = 0;
@@ -6359,7 +6419,6 @@ search_brick_path_from_proc(pid_t brick_pid, char *bri
             0,
         },
     };
-    char *brick_path = NULL;
 
     if (!brickpath)
         goto out;
@@ -6396,6 +6455,7 @@ search_brick_path_from_proc(pid_t brick_pid, char *bri
     }
 out:
     sys_closedir(dirp);
+#endif
     return brick_path;
 }
 
