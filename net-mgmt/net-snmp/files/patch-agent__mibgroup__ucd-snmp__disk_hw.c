--- ./agent/mibgroup/ucd-snmp/disk_hw.c.orig	2011-09-28 00:53:47.000000000 -0400
+++ ./agent/mibgroup/ucd-snmp/disk_hw.c	2012-02-13 11:07:08.000000000 -0500
@@ -137,6 +137,7 @@
   if (disks) {
      free( disks );
      disks = NULL;
+     maxdisks = numdisks = 0;
   }
   allDisksIncluded = 0;
 }
@@ -321,7 +322,7 @@
 
     switch (vp->magic) {
     case MIBINDEX:
-        long_ret = disknum;
+        long_ret = disknum + 1;
         return ((u_char *) (&long_ret));
     case ERRORNAME:            /* DISKPATH */
         *var_len = strlen(entry->path);
