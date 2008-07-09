--- sys_freebsd.c.orig	2004-05-15 05:44:11.000000000 +0200
+++ sys_freebsd.c	2008-06-23 23:59:01.000000000 +0200
@@ -17,11 +17,7 @@
  *
  */
 
-#include <kvm.h>
-#include <fcntl.h>
 #include <sys/types.h>
-#include <sys/dkstat.h>
-#include <sys/vmmeter.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
@@ -35,13 +31,6 @@
 
 extern BubbleMonData bm;
 
-static kvm_t *kd = NULL;
-static struct nlist nlst[] = {
-    {"_cp_time", 0},
-    {"_cnt", 0},
-    {"_bufspace", 0},
-    {0, 0}
-};
 static int pageshift;
 
 #define pagetob(size) ((size) << pageshift)
@@ -57,21 +46,6 @@
 	pagesize >>= 1;
     }
 
-    /* open kernel memory */
-    kd = kvm_open(NULL, NULL, NULL, O_RDONLY, "kvm_open");
-
-    if (kd == NULL) {
-	puts("Could not open kernel virtual memory");
-	return 1;
-    }
-
-    kvm_nlist(kd, nlst);
-
-    if (nlst[0].n_type == 0 || nlst[1].n_type == 0 || nlst[2].n_type == 0) {
-	puts("Error extracting symbols");
-	return 2;
-    }
-
     /* drop setgid & setuid (the latter should not be there really) */
     seteuid(getuid());
     setegid(getgid());
@@ -91,10 +65,10 @@
     int previous_total, previous_load;
     int total, load;
     unsigned long int cpu_time[CPUSTATES];
+    size_t old_len = sizeof(cpu_time);
     int i;
 
-    if (kvm_read(kd, nlst[0].n_value, &cpu_time, sizeof(cpu_time))
-	!= sizeof(cpu_time))
+    if(sysctlbyname("kern.cp_time", &cpu_time, &old_len, NULL, 0))
 	return 0;
 
     load = cpu_time[CP_USER] + cpu_time[CP_SYS] + cpu_time[CP_NICE];
@@ -124,44 +98,57 @@
 {
     u_int64_t my_mem_used, my_mem_max;
     u_int64_t my_swap_used, my_swap_max;
-    struct vmmeter sum;
     int bufspace;
+    int page_count;
+    int active_count;
+    int swap_in;
+    int swap_out;
+    size_t old_len = sizeof(int);
     static int swappgsin = -1;
     static int swappgsout = -1;
     static int swap_firsttime = 1;
     static int swapavail = 0, swapused = 0;
     static time_t last_time_swap = 0;
     time_t curr_time;
-	
-    if (kvm_read(kd, nlst[1].n_value, &sum, sizeof(sum)) != sizeof(sum))
-	return 0;		/* _cnt */
+    struct xswdev xswp;
+
+    if(sysctlbyname("vm.stats.vm.v_page_count", &page_count, &old_len, NULL, 0))
+	return 0;
+
+    if(sysctlbyname("vm.stats.vm.v_active_count", &active_count, &old_len, NULL, 0))
+	return 0;
+
+    if(sysctlbyname("vfs.bufspace", &bufspace, &old_len, NULL, 0))
+	return 0;
+
+    if(sysctlbyname("vfs.stats.vm.vm_v_swappgsin", &swap_in, &old_len, NULL, 0))
+	return 0;
 
-    if (kvm_read(kd, nlst[2].n_value, &bufspace, sizeof(bufspace)) !=
-	sizeof(bufspace))
-	return 0;		/* _bufspace */
+    if(sysctlbyname("vfs.stats.vm.vm_v_swappgsout", &swap_out, &old_len, NULL, 0))
+	return 0;
 
-    my_mem_max = pagetob((u_int64_t) sum.v_page_count);
-    my_mem_used = pagetob((u_int64_t) sum.v_active_count);
+    old_len = sizeof(xswp);
+    if(sysctlbyname("vm.swapinfo", &xswp, &old_len, NULL, 0))
+	return 0;
+	
+    my_mem_max = pagetob((u_int64_t) page_count);
+    my_mem_used = pagetob((u_int64_t) active_count);
 
     /* only calculate when first time or when changes took place */
     /* do not call it more than 1 time per 2 seconds */
     /* otherwise it can eat up to 50% of CPU time on heavy swap activity */
     curr_time = time(NULL);
-    
+
     if (swap_firsttime ||
-	(((sum.v_swappgsin > swappgsin) || (sum.v_swappgsout > swappgsout)) &&
+	(((swap_in > swappgsin) || (swap_out > swappgsout)) &&
 	curr_time > last_time_swap + 1)) {
 	
-	struct kvm_swap swap;
-	int n;
-
 	swapavail = 0;
 	swapused = 0;
 
-	n = kvm_getswapinfo(kd, &swap, 1, 0);
-	if (n >= 0 && swap.ksw_total != 0) {
-	    swapavail = pagetob(swap.ksw_total);
-	    swapused = pagetob(swap.ksw_used);
+	if (xswp.xsw_nblks!= 0) {
+	    swapavail = pagetob(xswp.xsw_nblks);
+	    swapused = pagetob(xswp.xsw_used);
 	}
 
 	swap_firsttime = 0;
@@ -171,8 +158,8 @@
     my_swap_used = swapused;
     my_swap_max = swapavail;
 
-    swappgsin = sum.v_swappgsin;
-    swappgsout = sum.v_swappgsout;
+    swappgsin = swap_in;
+    swappgsout = swap_out;
 
     bm.mem_used = my_mem_used;
     bm.mem_max = my_mem_max;
