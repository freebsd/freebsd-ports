--- agent/mibgroup/host/hr_swrun.c~	Wed Mar 14 22:45:56 2001
+++ agent/mibgroup/host/hr_swrun.c	Tue Mar 27 12:37:57 2001
@@ -365,7 +365,11 @@
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
@@ -417,7 +421,11 @@
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
@@ -550,7 +558,11 @@
 	    }
 #else
 #if HAVE_KVM_GETPROCS
+#if defined(freebsd5) && __FreeBSD_version >= 500014
+	    switch ( proc_table[LowProcIndex].ki_stat ) {
+#else
 	    switch ( proc_table[LowProcIndex].kp_proc.p_stat ) {
+#endif
 #elif defined(solaris2)
 #if _SLASH_PROC_METHOD_
 	    switch (proc_buf ? proc_buf->pr_lwp.pr_state : SIDL) {
@@ -631,9 +643,17 @@
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
@@ -673,6 +693,13 @@
 #elif HAVE_KVM_GETPROCS
 #ifdef freebsd3
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
@@ -819,8 +846,13 @@
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
