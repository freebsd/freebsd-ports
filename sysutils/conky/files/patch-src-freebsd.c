--- src/freebsd.c.orig	2010-10-24 03:14:05.000000000 +0300
+++ src/freebsd.c	2010-10-24 03:13:05.000000000 +0300
@@ -266,7 +266,9 @@
 {
 	int n_processes;
 
+	pthread_mutex_lock(&kvm_proc_mutex);
 	kvm_getprocs(kd, KERN_PROC_ALL, 0, &n_processes);
+	pthread_mutex_unlock(&kvm_proc_mutex);
 
 	info.procs = n_processes;
 	return 0;
@@ -278,6 +280,7 @@
 	int n_processes;
 	int i, cnt = 0;
 
+	pthread_mutex_lock(&kvm_proc_mutex);
 	p = kvm_getprocs(kd, KERN_PROC_ALL, 0, &n_processes);
 	for (i = 0; i < n_processes; i++) {
 #if (__FreeBSD__ < 5) && (__FreeBSD_kernel__ < 5)
@@ -288,6 +291,7 @@
 			cnt++;
 		}
 	}
+	pthread_mutex_unlock(&kvm_proc_mutex);
 
 	info.run_procs = cnt;
 	return 0;
@@ -748,6 +752,7 @@
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
