--- wmtop.c.orig	2016-02-09 01:13:19 UTC
+++ wmtop.c
@@ -72,6 +72,13 @@
 #include "xpm/wmtop-neon2.xpm"
 #include "xpm/wmtop-rainbow.xpm"
 
+#ifdef NO_PROCFS
+#include <kvm.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#include <sys/resource.h>
+#endif
+
 /******************************************/
 /* Defines                                */
 /******************************************/
@@ -191,6 +198,9 @@ struct process {
     long rss;
     int time_stamp;
     int counted;
+#ifdef NO_PROCFS
+    struct kinfo_proc *kp;
+#endif
 };
 
 /******************************************/
@@ -455,17 +465,19 @@ int process_parse_procfs(struct process *process) {
  * Anyone hoping to port wmtop should look here first.
  */
 int process_parse_procfs(struct process *process) {
+#if !defined(NO_PROCFS)
     char line[WMTOP_BUFLENGTH],filename[WMTOP_BUFLENGTH],procname[WMTOP_BUFLENGTH];
     int ps;
     struct stat sbuf;
-    unsigned long user_time,kernel_time;
     int rc;
+#endif
+    unsigned long user_time,kernel_time;
 #if defined(LINUX)
     char *r,*q;
     char deparenthesised_name[WMTOP_BUFLENGTH];
 		int endl;
 #endif /* defined(LINUX) */
-#if defined(FREEBSD)
+#if defined(FREEBSD) && !defined(NO_PROCFS)
     /* TODO: needs analysis. Probably needs same data type fix as LINUX (use
      * long types). Need to check FreeBSD docs and test.  -wbk		     */
     int us,um,ks,km;
@@ -475,6 +487,15 @@ int process_parse_procfs(struct process *process) {
     assert(process->id==0x0badfeed);
 #endif /* defined(PARANOID) */
 
+#if defined(NO_PROCFS)
+#define GETV(u) ((u).tv_sec * 1000 + (u).tv_usec / 1000)
+    process->time_stamp = g_time;
+    if(process->name)
+        wmtop_free(process->name);
+    process->name = wmtop_strdup(process->kp->ki_comm);
+    process->user_time = GETV(process->kp->ki_rusage.ru_utime);
+    process->kernel_time = GETV(process->kp->ki_rusage.ru_stime);
+#else
     sprintf(filename,PROCFS_TEMPLATE,process->pid);
 
     /*
@@ -588,6 +609,7 @@ int process_parse_procfs(struct process *process) {
     process->user_time = us*1000+um/1000;
     process->kernel_time = ks*1000+km/1000;
 #endif /* defined(FREEBSD) */
+#endif /* defined(NO_PROCFS) */
 
     /* not portable (especially unsuitable for redistributable executables.
      * On some systems, getpagesize() is a preprocessor macro).
@@ -616,6 +638,39 @@ int update_process_table() {
 /******************************************/
 
 int update_process_table() {
+#if defined(NO_PROCFS)
+    kvm_t *kd;
+    int n;
+    struct kinfo_proc *p;
+
+    if((kd = kvm_open(NULL, "/dev/null", NULL, O_RDONLY, "wmtop")) == NULL)
+        return 1;
+
+    if((p = kvm_getprocs(kd, KERN_PROC_ALL, 0, &n)) == NULL)
+        return 1;
+
+    for(; n > 0; n --, p ++)
+    {
+      char **argv;
+      struct process *pp;
+
+      if((argv = kvm_getargv(kd, p, 0)) == NULL ||
+         argv[0] == NULL)
+        continue;
+
+      pp = find_process(p->ki_pid);
+      if(!pp)
+          pp = new_process(p->ki_pid);
+
+      pp->kp = p;
+      calculate_cpu(pp);
+    }
+
+    if(kvm_close(kd) != 0)
+        return 1;
+
+    return 0;
+#else
     DIR *dir;
     struct dirent *entry;
 
@@ -649,6 +704,7 @@ int update_process_table() {
     closedir(dir);
 
     return 0;
+#endif /* defined(NO_PROCFS) */
 }
 
 /******************************************/
