--- agent/mibgroup/host/hr_swrun.c.orig	Wed Jun  9 05:56:03 2004
+++ agent/mibgroup/host/hr_swrun.c	Fri Jun 25 10:56:38 2004
@@ -585,7 +585,7 @@
         string[ sizeof(string)-1 ] = 0;
 #endif
 #elif HAVE_KVM_GETPROCS
-    #if defined(freebsd5)
+    #if defined(freebsd5) && __FreeBSD_version >= 500014
         strcpy(string, proc_table[LowProcIndex].ki_comm);
     #else
         strcpy(string, proc_table[LowProcIndex].kp_proc.p_comm);
@@ -694,7 +694,7 @@
         *cp1 = 0;
 #endif
 #elif HAVE_KVM_GETPROCS
-    #if defined(freebsd5)
+    #if defined(freebsd5) && __FreeBSD_version >= 500014
         strcpy(string, proc_table[LowProcIndex].ki_comm);
     #else
         strcpy(string, proc_table[LowProcIndex].kp_proc.p_comm);
@@ -889,7 +889,7 @@
         }
 #else
 #if HAVE_KVM_GETPROCS
-    #if defined(freebsd5)
+    #if defined(freebsd5) && __FreeBSD_version >= 500014
         switch (proc_table[LowProcIndex].ki_stat) {
     #else
         switch (proc_table[LowProcIndex].kp_proc.p_stat) {
@@ -988,7 +988,13 @@
         long_return = proc_buf->p_utime * 100 + proc_buf->p_stime * 100;
 #endif
 #elif HAVE_KVM_GETPROCS
-    #if defined(freebsd5)
+    #if defined(freebsd5) && __FreeBSD_version >= 500014
+        /* XXX: Accessing ki_paddr causes sig10 ...
+        long_return = proc_table[LowProcIndex].ki_paddr->p_uticks +
+            proc_table[LowProcIndex].ki_paddr->p_sticks +
+            proc_table[LowProcIndex].ki_paddr->p_iticks; */
+        long_return = 0;
+    #elif defined(freebsd5)
         long_return = proc_table[LowProcIndex].ki_runtime / 100000;
     #else
         long_return = proc_table[LowProcIndex].kp_proc.p_uticks +
@@ -1063,7 +1069,14 @@
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
     #if defined(freebsd5)
             proc_table[LowProcIndex].ki_size / 1024;
@@ -1349,7 +1362,7 @@
 #elif defined(solaris2)
         return proc_table[current_proc_entry++];
 #elif HAVE_KVM_GETPROCS
-    #if defined(freebsd5)
+    #if defined(freebsd5) && __FreeBSD_version >= 500014
         if (proc_table[current_proc_entry].ki_stat != 0)
             return proc_table[current_proc_entry++].ki_pid;
     #else
