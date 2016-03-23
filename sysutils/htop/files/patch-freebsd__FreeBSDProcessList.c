--- freebsd/FreeBSDProcessList.c.orig	2016-02-10 12:48:39.000000000 -0800
+++ freebsd/FreeBSDProcessList.c	2016-02-13 13:42:40.759431578 -0800
@@ -84,6 +84,8 @@
 static int MIB_kern_cp_times[2];
 static int kernelFScale;
 
+// XXX hack
+static unsigned long long int Global_totalMem;
 
 ProcessList* ProcessList_new(UsersTable* usersTable, Hashtable* pidWhiteList, uid_t userId) {
    FreeBSDProcessList* fpl = xCalloc(1, sizeof(FreeBSDProcessList));
@@ -301,6 +303,8 @@
    //pl->totalMem *= pageSizeKb;
    sysctl(MIB_hw_physmem, 2, &(pl->totalMem), &len, NULL, 0);
    pl->totalMem /= 1024;
+   // XXX hack
+   Global_totalMem = pl->totalMem;
 
    sysctl(MIB_vm_stats_vm_v_active_count, 4, &(fpl->memActive), &len, NULL, 0);
    fpl->memActive *= pageSizeKb;
@@ -477,8 +481,9 @@
       }
 
       // from FreeBSD source /src/usr.bin/top/machine.c
-      proc->m_size = kproc->ki_size / 1024;
-      proc->m_resident = kproc->ki_rssize * pageSizeKb;
+      proc->m_size = kproc->ki_size / 1024 / pageSizeKb;
+      proc->m_resident = kproc->ki_rssize;
+      proc->percent_mem = (proc->m_resident * PAGE_SIZE_KB) / (double)(Global_totalMem) * 100.0;
       proc->nlwp = kproc->ki_numthreads;
       proc->time = (kproc->ki_runtime + 5000) / 10000;
 
@@ -487,9 +492,6 @@
          // system idle process should own all CPU time left regardless of CPU count
          if ( strcmp("idle", kproc->ki_comm) == 0 ) {
             isIdleProcess = true;
-         } else {
-            if (cpus > 1)
-               proc->percent_cpu = proc->percent_cpu / (double) cpus;
          }
       }
       if (isIdleProcess == false && proc->percent_cpu >= 99.8) {
