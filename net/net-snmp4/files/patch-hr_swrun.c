--- agent/mibgroup/host/hr_swrun.c.orig	Tue Oct  3 13:36:38 2000
+++ agent/mibgroup/host/hr_swrun.c	Fri Feb  2 11:27:39 2001
@@ -216,15 +216,15 @@
         if ( pid == -1 )
 	    break;
 	newname[HRSWRUN_ENTRY_NAME_LENGTH] = pid;
-    DEBUGMSGOID(("host/hr_swrun", newname, *length));
-    DEBUGMSG(("host/hr_swrun","\n"));
+	DEBUGMSGOID(("host/hr_swrun", newname, *length));
+	DEBUGMSG(("host/hr_swrun","\n"));
         result = snmp_oid_compare(name, *length, newname, vp->namelen + 1);
         if (exact && (result == 0)) {
 	    LowPid = pid;
 #ifndef linux
 	    LowProcIndex = current_proc_entry-1;
 #endif
-DEBUGMSGTL(("host/hr_swrun", " saved\n"));
+	    DEBUGMSGTL(("host/hr_swrun", " saved\n"));
 	    /* Save process status information */
             break;
 	}
@@ -235,9 +235,9 @@
 	    LowProcIndex = current_proc_entry-1;
 #endif
 	    /* Save process status information */
-DEBUGMSG(("host/hr_swrun", " saved"));
+	    DEBUGMSG(("host/hr_swrun", " saved"));
 	}
-DEBUGMSG(("host/hr_swrun", "\n"));
+	DEBUGMSG(("host/hr_swrun", "\n"));
     }
 
     if ( LowPid == -1 ) {
@@ -279,16 +279,16 @@
 #elif defined(solaris2)
 #if _SLASH_PROC_METHOD_
     static psinfo_t psinfo;
-    static psinfo_t *proc_buf = &psinfo;
+    static psinfo_t *proc_buf;
     int procfd;
     char procfn[sizeof "/proc/00000/psinfo"];
 #else
     static struct proc *proc_buf;
+    char *cp1;
 #endif	/* _SLASH_PROC_METHOD_ */
     static time_t when = 0;
     time_t now;
     static int oldpid = -1;
-    char *cp1;
 #endif
 #if HAVE_KVM_GETPROCS
     char **argv;
@@ -321,10 +321,13 @@
     }
     if (oldpid != pid || proc_buf == NULL) {
 #if _SLASH_PROC_METHOD_
+	proc_buf = &psinfo;
 	sprintf(procfn, "/proc/%.5d/psinfo", pid);
-	if ((procfd = open(procfn, O_RDONLY)) == -1) return NULL;
-	if (read(procfd, proc_buf, sizeof(*proc_buf)) != sizeof(*proc_buf)) abort();
-	close(procfd);
+	if ((procfd = open(procfn, O_RDONLY)) != -1) {
+		if (read(procfd, proc_buf, sizeof(*proc_buf)) != sizeof(*proc_buf)) abort();
+		close(procfd);
+	} else
+		proc_buf = NULL;
 #else
 	if (kd == NULL) return NULL;
 	if ((proc_buf = kvm_getproc(kd, pid)) == NULL) return NULL;
@@ -340,8 +343,8 @@
 		return NULL;
 #else
 	    long_return = 1;		/* Probably! */
-#endif
 	    return (u_char *)&long_return;
+#endif
 
 	case HRSWRUN_INDEX:
 	    long_return = pid;
@@ -354,12 +357,19 @@
 		*cp = '\0';
 #elif defined(solaris2)
 #if _SLASH_PROC_METHOD_
-	    strcpy(string, proc_buf->pr_fname);
+	    if (proc_buf)
+		    strcpy(string, proc_buf->pr_fname);
+	    else
+		    strcpy(string, "<exited>");
 #else
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
@@ -398,7 +408,10 @@
 		*cp = '\0';
 #elif defined(solaris2)
 #ifdef _SLASH_PROC_METHOD_
-	    strcpy(string, proc_buf->pr_psargs);
+	    if (proc_buf)
+	        strcpy(string, proc_buf->pr_psargs);
+	    else
+		sprintf(string, "<exited>");
 	    cp = strchr(string, ' ');
 	    if (cp) *cp = 0;
 #else
@@ -408,7 +421,11 @@
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
@@ -448,9 +465,12 @@
 		string[0] = '\0';
 #elif defined(solaris2)
 #ifdef _SLASH_PROC_METHOD_
-	    cp = strchr(proc_buf->pr_psargs, ' ');
-	    if (cp) strcpy(string, cp+1);
-	    else string[0] = 0;
+	    if (proc_buf) {
+	        cp = strchr(proc_buf->pr_psargs, ' ');
+	        if (cp) strcpy(string, cp+1);
+	        else string[0] = 0;
+	    } else
+		string[0] = 0;
 #else
 	    cp = proc_buf->p_user.u_psargs;
 	    while (*cp && *cp != ' ') cp++;
@@ -470,9 +490,15 @@
 	    sprintf( string, "/proc/%d/cmdline", pid );
 	    if ((fp = fopen( string, "r")) == NULL) return NULL;
 	    memset( buf, 0, sizeof(buf) );
-	    if(!fgets( buf, sizeof(buf)-2, fp ))
-		return NULL;   /* argv[0] '\0' argv[1] '\0' .... */
 
+                /* argv[0] '\0' argv[1] '\0' .... */
+	    if(!fgets( buf, sizeof(buf)-2, fp )) {
+                /* maybe be empty (even argv[0] is missing) */
+                string[0] = '\0';
+                *var_len = 0;
+                return string;
+            }
+            
 		/* Skip over argv[0] */
 	    cp = buf;
 	    while ( *cp )
@@ -531,10 +557,14 @@
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
-	    switch (proc_buf->pr_lwp.pr_state) {
+	    switch (proc_buf ? proc_buf->pr_lwp.pr_state : SIDL) {
 #else
 	    switch ( proc_buf->p_stat ) {
 #endif
@@ -566,32 +596,34 @@
 #endif
 #else
 	    sprintf( string, "/proc/%d/stat", pid );
-	    if ((fp = fopen( string, "r")) == NULL) return NULL;
-	    fgets( buf, sizeof(buf), fp );
-	    cp = buf;
-	    for ( i = 0 ; i < 2 ; ++i ) {	/* skip two fields */
-		while ( *cp != ' ')
+	    if ((fp = fopen( string, "r")) != NULL) {
+		fgets( buf, sizeof(buf), fp );
+		cp = buf;
+		for ( i = 0 ; i < 2 ; ++i ) {	/* skip two fields */
+		    while ( *cp != ' ')
+			++cp;
 		    ++cp;
-		++cp;
-	    }
+		}
 
-	    switch ( *cp ) {
-		case 'R':
+		switch ( *cp ) {
+		    case 'R':
 	    		long_return = 1;	/* running */
 			break;
-		case 'S':
+		    case 'S':
 	    		long_return = 2;	/* runnable */
 			break;
-		case 'D':
-		case 'T':
+		    case 'D':
+		    case 'T':
 	    		long_return = 3;	/* notRunnable */
 			break;
-		case 'Z':
-		default:
+		    case 'Z':
+		    default:
 	    		long_return = 4;	/* invalid */
 			break;
-	    }
-            fclose(fp);
+		}
+                fclose(fp);
+	    } else
+		long_return = 4;		/* invalid */
 #endif
 	    return (u_char *)&long_return;
 
@@ -603,16 +635,24 @@
 				 */
 #elif defined(solaris2)
 #if _SLASH_PROC_METHOD_
-	    long_return = proc_buf->pr_time.tv_sec * 100 +
-			  proc_buf->pr_time.tv_nsec/10000000;
+	    long_return = proc_buf ? proc_buf->pr_time.tv_sec * 100 +
+			  proc_buf->pr_time.tv_nsec/10000000 : 0;
 #else
 	    long_return = proc_buf->p_utime*100 +
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
@@ -645,13 +685,20 @@
 	    long_return = (proc_buf.pst_rssize << PGSHIFT)/1024;
 #elif defined(solaris2)
 #if _SLASH_PROC_METHOD_
-	    long_return = proc_buf->pr_rssize;
+	    long_return = proc_buf ? proc_buf->pr_rssize : 0;
 #else
 	    long_return = proc_buf->p_swrss;
 #endif
 #elif HAVE_KVM_GETPROCS
-#ifdef freebsd3
+#if defined(freebsd3)
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
@@ -747,6 +794,10 @@
     }
 #elif HAVE_KVM_GETPROCS
     {
+	if (kd == NULL) {
+	    nproc = 0;
+	    return;
+	}
 	proc_table = kvm_getprocs(kd, KERN_PROC_ALL, 0, &nproc);
     }
 #else
@@ -794,8 +845,13 @@
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
@@ -853,7 +909,7 @@
 
 int count_processes (void)
 {
-#ifndef linux
+#if !(defined(linux) || defined(hpux10) || defined(solaris2) || HAVE_KVM_GETPROCS)
     int i;
 #endif
     int total=0;
