--- agent/mibgroup/host/hr_swrun.c.orig	Sat Feb 16 09:41:19 2002
+++ agent/mibgroup/host/hr_swrun.c	Sat Feb 16 23:41:05 2002
@@ -543,7 +543,11 @@
 	    strcpy(string, proc_buf->p_user.u_comm);
 #endif
 #elif HAVE_KVM_GETPROCS
+#if defined(freebsd5) && __FreeBSD_version >= 500014
+            strcpy(string, proc_table[LowProcIndex].ki_comm);
+#else
             strcpy(string, proc_table[LowProcIndex].kp_proc.p_comm);
+#endif
 #elif defined(linux)
 	    sprintf( string, "/proc/%d/status", pid );
 	    if ((fp = fopen( string, "r")) == NULL) return NULL;
@@ -638,7 +642,11 @@
 	    *cp1 = 0;
 #endif
 #elif HAVE_KVM_GETPROCS
+#if defined(freebsd5) && __FreeBSD_version >= 500014
+            strcpy(string, proc_table[LowProcIndex].ki_comm);
+#else
             strcpy(string, proc_table[LowProcIndex].kp_proc.p_comm);
+#endif
 #elif defined(linux)
 	    sprintf( string, "/proc/%d/cmdline", pid );
 	    if ((fp = fopen( string, "r")) == NULL) return NULL;
@@ -810,7 +818,11 @@
 	    }
 #else
 #if HAVE_KVM_GETPROCS
+#if defined(freebsd5) && __FreeBSD_version >= 500014
+	    switch ( proc_table[LowProcIndex].ki_stat ) {
+#else
 	    switch ( proc_table[LowProcIndex].kp_proc.p_stat ) {
+#endif
 #elif defined(dynix)
 	    switch ( lowpsinfo.pr_state ) {
 #elif defined(solaris2)
@@ -906,9 +918,17 @@
 	    		  proc_buf->p_stime*100;
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
 	    sprintf( string, "/proc/%d/stat", pid );
 	    if ((fp = fopen( string, "r")) == NULL) return NULL;
@@ -976,6 +996,13 @@
 #elif HAVE_KVM_GETPROCS
 #if defined(freebsd3) && !defined(darwin)
 	    long_return = proc_table[LowProcIndex].kp_eproc.e_vm.vm_map.size/1024;
+#elif defined(freebsd5) && __FreeBSD_version >= 500014
+	    /* XXX
+	    long_return = proc_table[LowProcIndex].ki_vmspace->vm_tsize +
+			  proc_table[LowProcIndex].ki_vmspace->vm_ssize +
+			  proc_table[LowProcIndex].ki_vmspace->vm_dsize;
+	    long_return = long_return * (getpagesize() / 1024); */
+	    long_return = 0;
 #else
 	    long_return = proc_table[LowProcIndex].kp_eproc.e_vm.vm_tsize +
 			  proc_table[LowProcIndex].kp_eproc.e_vm.vm_ssize +
@@ -1237,8 +1264,13 @@
 #elif defined(solaris2)
 	return proc_table[current_proc_entry++];
 #elif HAVE_KVM_GETPROCS
+#if defined(freebsd5) && __FreeBSD_version >= 500014
+	if ( proc_table[current_proc_entry].ki_stat != 0 )
+	    return proc_table[current_proc_entry++].ki_pid;
+#else
 	if ( proc_table[current_proc_entry].kp_proc.p_stat != 0 )
 	    return proc_table[current_proc_entry++].kp_proc.p_pid;
+#endif
 #else
 	if ( proc_table[current_proc_entry].p_stat != 0 )
 	    return proc_table[current_proc_entry++].p_pid;
