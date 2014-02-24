--- ./agent/mibgroup/host/data_access/swrun_kinfo.c.orig	2012-10-09 18:28:58.000000000 -0400
+++ ./agent/mibgroup/host/data_access/swrun_kinfo.c	2014-02-24 14:33:08.000000000 -0500
@@ -186,7 +186,7 @@
 #if HAVE_KVM_GETPROC2
         argv = kvm_getargv2( kd, &(proc_table[i]), 0);
 #else
-        argv = kvm_getargv(  kd, &(proc_table[i]), 0);
+        argv = kvm_getargv(  kd, &(proc_table[i]), BUFSIZ);
 #endif
 
         entry->hrSWRunName_len = snprintf(entry->hrSWRunName,
@@ -219,8 +219,8 @@
         if (argv)
             argv++;    /* Skip argv[0] */
         while ( argv && *argv ) {
-            strcat(buf, " ");
-            strcat(buf, *argv);
+	    strncat(buf, " ", sizeof(buf) - strlen(buf) - 1);
+	    strncat(buf, *argv, sizeof(buf) - strlen(buf) - 1);
             argv++;
         }
         entry->hrSWRunParameters_len = snprintf(entry->hrSWRunParameters,
