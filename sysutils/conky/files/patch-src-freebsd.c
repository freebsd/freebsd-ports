--- src/freebsd.c.orig	2010-10-06 00:29:36.000000000 +0300
+++ src/freebsd.c	2012-03-05 01:02:25.000000000 +0200
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
@@ -266,7 +271,9 @@
 {
 	int n_processes;
 
+	pthread_mutex_lock(&kvm_proc_mutex);
 	kvm_getprocs(kd, KERN_PROC_ALL, 0, &n_processes);
+	pthread_mutex_unlock(&kvm_proc_mutex);
 
 	info.procs = n_processes;
 	return 0;
@@ -278,9 +285,10 @@
 	int n_processes;
 	int i, cnt = 0;
 
+	pthread_mutex_lock(&kvm_proc_mutex);
 	p = kvm_getprocs(kd, KERN_PROC_ALL, 0, &n_processes);
 	for (i = 0; i < n_processes; i++) {
-#if (__FreeBSD__ < 5) && (__FreeBSD_kernel__ < 5)
+#if (defined(__FreeBSD__) && (__FreeBSD__ < 5)) || (defined(__FreeBSD_kernel__) && (__FreeBSD_kernel__ < 5))
 		if (p[i].kp_proc.p_stat == SRUN) {
 #else
 		if (p[i].ki_stat == SRUN) {
@@ -288,6 +296,7 @@
 			cnt++;
 		}
 	}
+	pthread_mutex_unlock(&kvm_proc_mutex);
 
 	info.run_procs = cnt;
 	return 0;
@@ -296,7 +305,6 @@
 void get_cpu_count(void)
 {
 	int cpu_count = 0;
-	size_t cpu_count_len = sizeof(cpu_count);
 
 	if (GETSYSCTL("hw.ncpu", cpu_count) == 0) {
 		info.cpu_count = cpu_count;
@@ -748,6 +756,7 @@
 		CRIT_ERR(NULL, NULL, "Cannot read sysctl \"vm.stats.vm.v_page_count\"");
 	}
 
+	pthread_mutex_lock(&kvm_proc_mutex);
 	p = kvm_getprocs(kd, KERN_PROC_PROC, 0, &n_processes);
 	processes = malloc(n_processes * sizeof(struct process));
 
@@ -764,6 +769,7 @@
 			j++;
 		}
 	}
+	pthread_mutex_unlock(&kvm_proc_mutex);
 
 	qsort(processes, j - 1, sizeof(struct process), comparemem);
 	for (i = 0; i < 10 && i < n_processes; i++) {
