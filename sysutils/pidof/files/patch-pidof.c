--- pidof.c.orig	2005-05-01 16:26:19 UTC
+++ pidof.c
@@ -53,10 +53,19 @@ get_pid_of_process(char *process_name)
 	if ((kd = kvm_open("/dev/null", "/dev/null", "/dev/null", O_RDONLY, "kvm_open")) == NULL) 
 			 (void)errx(1, "%s", kvm_geterr(kd));
 	else {
+#if __FreeBSD__ < 5
+		p = kvm_getprocs(kd, KERN_PROC_ALL, 0, &n_processes);
+#else
 		p = kvm_getprocs(kd, KERN_PROC_PROC, 0, &n_processes);
+#endif /* __FreeBSD__ < 5 */
 		for (i = 0; i<n_processes; i++)
+#if __FreeBSD__ < 5
+			if (strncmp(process_name, p[i].kp_proc.p_comm, MAXCOMLEN+1) == 0) {
+				(void)printf("%d ", (int)p[i].kp_proc.p_pid);
+#else
 			if (strncmp(process_name, p[i].ki_comm, COMMLEN+1) == 0) {
 				(void)printf("%d ", (int)p[i].ki_pid);
+#endif /* __FreeBSD__ < 5 */
 				processes_found++;
 			}
 
