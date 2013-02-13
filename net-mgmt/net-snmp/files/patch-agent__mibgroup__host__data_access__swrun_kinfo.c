--- ./agent/mibgroup/host/data_access/swrun_kinfo.c.orig	2012-10-09 18:28:58.000000000 -0400
+++ ./agent/mibgroup/host/data_access/swrun_kinfo.c	2013-02-12 18:55:42.000000000 -0500
@@ -186,7 +186,7 @@
 #if HAVE_KVM_GETPROC2
         argv = kvm_getargv2( kd, &(proc_table[i]), 0);
 #else
-        argv = kvm_getargv(  kd, &(proc_table[i]), 0);
+        argv = kvm_getargv(  kd, &(proc_table[i]), BUFSIZ);
 #endif
 
         entry->hrSWRunName_len = snprintf(entry->hrSWRunName,
