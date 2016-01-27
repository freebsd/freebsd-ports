Fix the build on FreeBSD 9:

cc1: warnings being treated as errors
platform/freebsd/freebsd.c: In function 'check_proc_stopped':
platform/freebsd/freebsd.c:57: warning: 'state' may be used uninitialized in this function
--- platform/freebsd/freebsd.c.orig	2015-06-05 21:41:48 UTC
+++ platform/freebsd/freebsd.c
@@ -54,7 +54,7 @@ int check_pgroup(pid_t target) {
 int check_proc_stopped(pid_t pid, int fd) {
     struct procstat *procstat;
     struct kinfo_proc *kp;
-    int state;
+    int state = 0;
     unsigned int cnt;
 
     procstat = procstat_open_sysctl();
