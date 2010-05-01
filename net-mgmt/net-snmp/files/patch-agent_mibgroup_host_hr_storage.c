--- agent/mibgroup/host/hr_storage.c.orig	2008-06-05 18:11:53.000000000 -0300
+++ agent/mibgroup/host/hr_storage.c	2010-04-30 21:39:50.000000000 -0300
@@ -523,12 +523,12 @@
 	    return NULL;
 
         store_idx = name[ HRSTORE_ENTRY_NAME_LENGTH ];
-        if (HRFS_entry &&
-            netsnmp_ds_get_boolean(NETSNMP_DS_APPLICATION_ID,
-                                   NETSNMP_DS_AGENT_SKIPNFSINHOSTRESOURCES) &&
-            Check_HR_FileSys_NFS())
-            return NULL;
-        if (store_idx > NETSNMP_MEM_TYPE_MAX ) {
+        if (store_idx > NETSNMP_MEM_TYPE_MAX ) {	   
+	   if (netsnmp_ds_get_boolean(NETSNMP_DS_APPLICATION_ID,
+				      NETSNMP_DS_AGENT_SKIPNFSINHOSTRESOURCES) &&
+	       Check_HR_FileSys_NFS())
+	     return NULL;
+
 	    if (HRFS_statfs(HRFS_entry->HRFS_mount, &stat_buf) < 0) {
 		snmp_log_perror(HRFS_entry->HRFS_mount);
 		goto try_next;
