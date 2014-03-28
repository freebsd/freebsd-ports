--- src/freebsd.c.orig	2012-05-04 06:08:27.000000000 +0900
+++ src/freebsd.c	2013-08-05 09:02:37.000000000 +0900
@@ -38,6 +38,11 @@
 #include <sys/types.h>
 #include <sys/user.h>
 
+#if defined(__FreeBSD__) && (!defined(__FreeBSD_kernel__) || !(__FreeBSD_kernel__ + 0))
+# undef __FreeBSD_kernel__
+# define __FreeBSD_kernel__ __FreeBSD__
+#endif
+
 #include <net/if.h>
 #include <net/if_mib.h>
 #include <net/if_media.h>
@@ -283,7 +288,7 @@
 	pthread_mutex_lock(&kvm_proc_mutex);
 	p = kvm_getprocs(kd, KERN_PROC_ALL, 0, &n_processes);
 	for (i = 0; i < n_processes; i++) {
-#if (__FreeBSD__ < 5) && (__FreeBSD_kernel__ < 5)
+#if (defined(__FreeBSD__) && (__FreeBSD__ < 5)) || (defined(__FreeBSD_kernel__) && (__FreeBSD_kernel__ < 5))
 		if (p[i].kp_proc.p_stat == SRUN) {
 #else
 		if (p[i].ki_stat == SRUN) {
@@ -300,7 +305,9 @@
 void get_cpu_count(void)
 {
 	int cpu_count = 0;
-	size_t cpu_count_len = sizeof(cpu_count);
+	/* add check for !info.cpu_usage since that mem is freed on a SIGUSR1 */
+	if ((cpu_setup == 1) && (info.cpu_usage))
+		return;
 
 	if (GETSYSCTL("hw.ncpu", cpu_count) == 0) {
 		info.cpu_count = cpu_count;
@@ -313,6 +320,7 @@
 	if (info.cpu_usage == NULL) {
 		CRIT_ERR(NULL, NULL, "malloc");
 	}
+	cpu_setup = 1;
 }
 
 struct cpu_info {
@@ -330,11 +338,7 @@
 	unsigned int malloc_cpu_size = 0;
 	extern void* global_cpu;
 
-	/* add check for !info.cpu_usage since that mem is freed on a SIGUSR1 */
-	if ((cpu_setup == 0) || (!info.cpu_usage)) {
-		get_cpu_count();
-		cpu_setup = 1;
-	}
+	get_cpu_count();
 
 	if (!global_cpu) {
 		malloc_cpu_size = (info.cpu_count + 1) * sizeof(struct cpu_info);
@@ -702,7 +706,7 @@
 		free(dev_select);
 	}
 
-	free(statinfo_cur.dinfo);
+	free(statinfo_cur.dinfo->mem_ptr);
 	return 0;
 }

