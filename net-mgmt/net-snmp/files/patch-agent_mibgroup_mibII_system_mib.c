--- agent/mibgroup/mibII/system_mib.c.orig	2010-06-11 13:43:01.000000000 +0200
+++ agent/mibgroup/mibII/system_mib.c	2010-06-11 13:45:21.000000000 +0200
@@ -61,6 +61,7 @@
 static char     sysLocation[SYS_STRING_LEN] = NETSNMP_SYS_LOC;
 static oid      sysObjectID[MAX_OID_LEN];
 static size_t   sysObjectIDLength;
+static size_t   sysObjectID_sizeof;
 
 extern oid      version_sysoid[];
 extern int      version_sysoid_len;
@@ -178,6 +179,7 @@
         memcpy(sysObjectID, version_sysoid, version_sysoid_len * sizeof(oid));
         sysObjectIDLength = version_sysoid_len;
     }
+    sysObjectID_sizeof = sysObjectIDLength * sizeof(oid);
 }
 
 
@@ -319,6 +321,7 @@
     /* default sysObjectID */
     memcpy(sysObjectID, version_sysoid, version_sysoid_len * sizeof(oid));
     sysObjectIDLength = version_sysoid_len;
+    sysObjectID_sizeof = sysObjectIDLength * sizeof(oid);
 
     {
         const oid sysDescr_oid[] = { 1, 3, 6, 1, 2, 1, 1, 1 };
@@ -341,7 +344,7 @@
             netsnmp_init_watcher_info6(
 		&sysObjectID_winfo, sysObjectID, 0, ASN_OBJECT_ID,
 		WATCHER_MAX_SIZE | WATCHER_SIZE_IS_PTR,
-		MAX_OID_LEN, &sysObjectIDLength));
+		MAX_OID_LEN, &sysObjectID_sizeof));
     }
     {
         const oid sysUpTime_oid[] = { 1, 3, 6, 1, 2, 1, 1, 3 };

