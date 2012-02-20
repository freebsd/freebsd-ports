--- agent/mibgroup/ucd-snmp/disk_hw.c.orig	2011-09-27 20:53:47.000000000 -0800
+++ agent/mibgroup/ucd-snmp/disk_hw.c	2012-02-19 16:21:29.000000000 -0900
@@ -137,6 +137,7 @@
   if (disks) {
      free( disks );
      disks = NULL;
+     maxdisks = numdisks = 0;
   }
   allDisksIncluded = 0;
 }
@@ -189,7 +190,7 @@
   if ( entry ) {
       entry->minspace   = minspace;
       entry->minpercent = minpercent;
-      entry->flags     |= ~NETSNMP_FS_FLAG_UCD;
+      entry->flags     |= NETSNMP_FS_FLAG_UCD;
       disks[numdisks++] = entry;
   }
 }
@@ -321,7 +322,7 @@
 
     switch (vp->magic) {
     case MIBINDEX:
-        long_ret = disknum;
+        long_ret = disknum + 1;
         return ((u_char *) (&long_ret));
     case ERRORNAME:            /* DISKPATH */
         *var_len = strlen(entry->path);
