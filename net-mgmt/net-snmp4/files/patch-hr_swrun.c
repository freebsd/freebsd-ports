--- agent/mibgroup/host/hr_swrun.c.orig	2006-06-06 08:11:59.000000000 +0000
+++ agent/mibgroup/host/hr_swrun.c	2008-04-30 11:30:47.000000000 +0000
@@ -549,7 +549,7 @@
             string[ sizeof(string)-1 ] = 0;
 #endif
 #elif HAVE_KVM_GETPROCS
-    #if defined(freebsd5)
+    #if defined(freebsd5) && __FreeBSD_version >= 500014
             strcpy(string, proc_table[LowProcIndex].ki_comm);
     #else
             strcpy(string, proc_table[LowProcIndex].kp_proc.p_comm);
@@ -648,7 +648,7 @@
 	    *cp1 = 0;
 #endif
 #elif HAVE_KVM_GETPROCS
-    #if defined(freebsd5)
+    #if defined(freebsd5) && __FreeBSD_version >= 500014
             strcpy(string, proc_table[LowProcIndex].ki_comm);
     #else
             strcpy(string, proc_table[LowProcIndex].kp_proc.p_comm);
@@ -827,7 +827,7 @@
 	    }
 #else
 #if HAVE_KVM_GETPROCS
-    #if defined(freebsd5)
+    #if defined(freebsd5) && __FreeBSD_version >= 500014
             switch ( proc_table[LowProcIndex].ki_stat ) {
     #else
             switch ( proc_table[LowProcIndex].kp_proc.p_stat ) {
@@ -927,7 +927,7 @@
 	    		  proc_buf->p_stime*100;
 #endif
 #elif HAVE_KVM_GETPROCS
-    #if defined(freebsd5)
+    #if defined(freebsd5) && __FreeBSD_version >= 500014
 	    long_return = proc_table[LowProcIndex].ki_runtime / 100000;
     #else
 	    long_return = proc_table[LowProcIndex].kp_proc.p_uticks +
@@ -1266,7 +1266,7 @@
 #elif defined(solaris2)
 	return proc_table[current_proc_entry++];
 #elif HAVE_KVM_GETPROCS
-    #if defined(freebsd5)
+    #if defined(freebsd5) && __FreeBSD_version >= 500014
 	if ( proc_table[current_proc_entry].ki_stat != 0 )
 	    return proc_table[current_proc_entry++].ki_pid;
     #else
