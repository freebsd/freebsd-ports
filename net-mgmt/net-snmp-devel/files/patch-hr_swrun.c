--- agent/mibgroup/host/hr_swrun.c.orig	Thu Oct 20 04:32:20 2005
+++ agent/mibgroup/host/hr_swrun.c	Wed Nov 30 12:50:12 2005
@@ -585,7 +585,7 @@
         string[ sizeof(string)-1 ] = 0;
 #endif
 #elif HAVE_KVM_GETPROCS
-    #if defined(freebsd5)
+    #if defined(freebsd5) && __FreeBSD_version >= 500014
         strcpy(string, proc_table[LowProcIndex].ki_comm);
     #else
         strcpy(string, proc_table[LowProcIndex].kp_proc.p_comm);
@@ -698,7 +698,7 @@
         *cp1 = 0;
 #endif
 #elif HAVE_KVM_GETPROCS
-    #if defined(freebsd5)
+    #if defined(freebsd5) && __FreeBSD_version >= 500014
         strcpy(string, proc_table[LowProcIndex].ki_comm);
     #else
         strcpy(string, proc_table[LowProcIndex].kp_proc.p_comm);
@@ -868,8 +868,23 @@
         if (pid < PID_MAXSYS)
             long_return = 2;    /* operatingSystem */
         else
-#endif
             long_return = 4;    /* application */
+#elif HAVE_KVM_GETPROCS
+    #if defined(freebsd5) && __FreeBSD_version >= 500014
+        if (proc_table[LowProcIndex].ki_flag & P_SYSTEM) {
+            if (proc_table[LowProcIndex].ki_pri.pri_class == PRI_ITHD)
+                long_return = 3;/* deviceDriver */
+            else
+                long_return = 2;/* operatingSystem */
+        } else
+            long_return = 4;    /* application */
+#else
+        if (proc_table[LowProcIndex].kp_proc.p_flag & P_SYSTEM)
+            long_return = 2;    /* operatingSystem */
+        else
+            long_return = 4;    /* application */
+#endif
+#endif
         return (u_char *) & long_return;
     case HRSWRUN_STATUS:
 #if defined(cygwin)
@@ -901,7 +916,7 @@
         }
 #else
 #if HAVE_KVM_GETPROCS
-    #if defined(freebsd5)
+    #if defined(freebsd5) && __FreeBSD_version >= 500014
         switch (proc_table[LowProcIndex].ki_stat) {
     #else
         switch (proc_table[LowProcIndex].kp_proc.p_stat) {
@@ -1000,7 +1015,13 @@
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
@@ -1365,7 +1386,7 @@
 #elif defined(solaris2)
         return proc_table[current_proc_entry++];
 #elif HAVE_KVM_GETPROCS
-    #if defined(freebsd5)
+    #if defined(freebsd5) && __FreeBSD_version >= 500014
         if (proc_table[current_proc_entry].ki_stat != 0)
             return proc_table[current_proc_entry++].ki_pid;
     #else
