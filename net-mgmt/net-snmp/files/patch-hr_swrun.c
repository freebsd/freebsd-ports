--- agent/mibgroup/host/hr_swrun.c.orig	Fri Dec 20 00:07:30 2002
+++ agent/mibgroup/host/hr_swrun.c	Sat Aug 16 17:10:54 2003
@@ -561,7 +561,11 @@
         string[ sizeof(string)-1 ] = 0;
 #endif
 #elif HAVE_KVM_GETPROCS
+#if defined(freebsd5) && __FreeBSD_version >= 500014
+            strcpy(string, proc_table[LowProcIndex].ki_comm);
+#else
         strcpy(string, proc_table[LowProcIndex].kp_proc.p_comm);
+#endif
 #elif defined(linux)
         sprintf(string, "/proc/%d/status", pid);
         if ((fp = fopen(string, "r")) == NULL)
@@ -666,7 +670,11 @@
         *cp1 = 0;
 #endif
 #elif HAVE_KVM_GETPROCS
+#if defined(freebsd5) && __FreeBSD_version >= 500014
+            strcpy(string, proc_table[LowProcIndex].ki_comm);
+#else
         strcpy(string, proc_table[LowProcIndex].kp_proc.p_comm);
+#endif
 #elif defined(linux)
         sprintf(string, "/proc/%d/cmdline", pid);
         if ((fp = fopen(string, "r")) == NULL)
@@ -857,7 +865,11 @@
         }
 #else
 #if HAVE_KVM_GETPROCS
+#if defined(freebsd5) && __FreeBSD_version >= 500014
+	    switch ( proc_table[LowProcIndex].ki_stat ) {
+#else
         switch (proc_table[LowProcIndex].kp_proc.p_stat) {
+#endif
 #elif defined(dynix)
         switch (lowpsinfo.pr_state) {
 #elif defined(solaris2)
@@ -952,9 +964,17 @@
         long_return = proc_buf->p_utime * 100 + proc_buf->p_stime * 100;
 #endif
 #elif HAVE_KVM_GETPROCS
+#if defined(freebsd5) && __FreeBSD_version >= 500014
+	    /* XXX: Accessing ki_paddr causes sig10 ...
+	    long_return = proc_table[LowProcIndex].ki_paddr->p_uticks +
+	    		  proc_table[LowProcIndex].ki_paddr->p_sticks +
+	    		  proc_table[LowProcIndex].ki_paddr->p_iticks; */
+	    long_return = 0;
+#else
         long_return = proc_table[LowProcIndex].kp_proc.p_uticks +
             proc_table[LowProcIndex].kp_proc.p_sticks +
             proc_table[LowProcIndex].kp_proc.p_iticks;
+#endif
 #elif defined(linux)
         sprintf(string, "/proc/%d/stat", pid);
         if ((fp = fopen(string, "r")) == NULL)
@@ -1023,7 +1043,14 @@
         long_return = proc_buf->p_swrss;
 #endif
 #elif HAVE_KVM_GETPROCS
-#if defined(freebsd3) && !defined(darwin)
+#if defined(freebsd5) && __FreeBSD_version >= 500014
+	    /* XXX
+	    long_return = proc_table[LowProcIndex].ki_vmspace->vm_tsize +
+			  proc_table[LowProcIndex].ki_vmspace->vm_ssize +
+			  proc_table[LowProcIndex].ki_vmspace->vm_dsize;
+	    long_return = long_return * (getpagesize() / 1024); */
+	    long_return = 0;
+#elif defined(freebsd3) && !defined(darwin)
         long_return =
             proc_table[LowProcIndex].kp_eproc.e_vm.vm_map.size / 1024;
 #else
@@ -1303,8 +1330,13 @@
 #elif defined(solaris2)
         return proc_table[current_proc_entry++];
 #elif HAVE_KVM_GETPROCS
+#if defined(freebsd5) && __FreeBSD_version >= 500014
+	if ( proc_table[current_proc_entry].ki_stat != 0 )
+	    return proc_table[current_proc_entry++].ki_pid;
+#else
         if (proc_table[current_proc_entry].kp_proc.p_stat != 0)
             return proc_table[current_proc_entry++].kp_proc.p_pid;
+#endif
 #else
         if (proc_table[current_proc_entry].p_stat != 0)
             return proc_table[current_proc_entry++].p_pid;
