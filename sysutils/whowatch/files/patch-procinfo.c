
$FreeBSD$

--- procinfo.c.orig
+++ procinfo.c
@@ -65,7 +65,7 @@
 int fill_kinfo(struct kinfo_proc *info, int pid)
 {
 	int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, pid };
-	int len = sizeof *info;
+	size_t len = sizeof *info;
 	if(sysctl(mib, 4, info, &len, 0, 0) == -1) 
 		return -1;
 	return len?0:-1;
@@ -124,7 +124,8 @@
 int get_login_pid(char *tty)
 {
 	int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_TTY, 0};
-	int len, t, el, i, pid, cndt = -1, l;
+	int t, el, i, pid, cndt = -1, l;
+	size_t len;
 	struct kinfo_proc *info;
 	struct procinfo p;
 	
@@ -169,7 +170,8 @@
 int get_all_info(struct kinfo_proc **info)
 {
 	int mib[3] = { CTL_KERN, KERN_PROC, KERN_PROC_ALL };
-	int len, el;
+	int el;
+	size_t len;
 
 	if(sysctl(mib, 3, 0, &len, 0, 0) == -1)
 		return 0;
