--- ./agent/mibgroup/host/data_access/swrun_kinfo.c.orig	2011-12-16 07:32:47.000000000 -0500
+++ ./agent/mibgroup/host/data_access/swrun_kinfo.c	2011-12-16 07:32:40.000000000 -0500
@@ -183,7 +183,7 @@
 #if HAVE_KVM_GETPROC2
         argv = kvm_getargv2( kd, &(proc_table[i]), 0);
 #else
-        argv = kvm_getargv(  kd, &(proc_table[i]), 0);
+        argv = kvm_getargv(  kd, &(proc_table[i]), BUFSIZ);
 #endif
 
         entry->hrSWRunName_len = snprintf(entry->hrSWRunName,
