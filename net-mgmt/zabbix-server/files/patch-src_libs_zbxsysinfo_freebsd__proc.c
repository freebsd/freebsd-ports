--- src/libs/zbxsysinfo/freebsd/proc.c.orig	2011-12-28 03:27:42.000000000 -0600
+++ src/libs/zbxsysinfo/freebsd/proc.c	2012-04-25 21:54:13.877489156 -0500
@@ -36,17 +36,13 @@
 #	define ZBX_PROC_PID	ki_pid
 #	define ZBX_PROC_COMM	ki_comm
 #	define ZBX_PROC_STAT	ki_stat
-#	define ZBX_PROC_TSIZE	ki_tsize
-#	define ZBX_PROC_DSIZE	ki_dsize
-#	define ZBX_PROC_SSIZE	ki_ssize
+#	define ZBX_PROC_VSIZE	ki_size
 #else
 #	define ZBX_COMMLEN	MAXCOMLEN
 #	define ZBX_PROC_PID	kp_proc.p_pid
 #	define ZBX_PROC_COMM	kp_proc.p_comm
 #	define ZBX_PROC_STAT	kp_proc.p_stat
-#	define ZBX_PROC_TSIZE	kp_eproc.e_vm.vm_tsize
-#	define ZBX_PROC_DSIZE	kp_eproc.e_vm.vm_dsize
-#	define ZBX_PROC_SSIZE	kp_eproc.e_vm.vm_ssize
+#	define ZBX_PROC_VSIZE	kp_eproc.e_vm.vm_map.size
 #endif
 
 static char	*get_commandline(struct kinfo_proc *proc)
@@ -97,7 +93,7 @@
 	char	procname[MAX_STRING_LEN],
 		buffer[MAX_STRING_LEN],
 		proccomm[MAX_STRING_LEN], *args;
-	int	do_task, pagesize, count, i,
+	int	do_task, count, i,
 		proc_ok, comm_ok,
 		mib[4], mibs;
 
@@ -152,8 +148,6 @@
 	if (0 != get_param(param, 4, proccomm, sizeof(proccomm)))
 		*proccomm = '\0';
 
-	pagesize = getpagesize();
-
 	mib[0] = CTL_KERN;
 	mib[1] = KERN_PROC;
 	if (NULL != usrinfo)
@@ -205,8 +198,7 @@
 
 		if (proc_ok && comm_ok)
 		{
-			value = proc[i].ZBX_PROC_TSIZE + proc[i].ZBX_PROC_DSIZE + proc[i].ZBX_PROC_SSIZE;
-			value *= pagesize;
+			value = proc[i].ZBX_PROC_VSIZE; /* vsize is bytes not pages */
 
 			if (0 == proccount++)
 				memsize = value;
