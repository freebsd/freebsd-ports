--- ./agent/mibgroup/ucd-snmp/disk_hw.c.orig	2012-01-27 09:51:02.000000000 -0500
+++ ./agent/mibgroup/ucd-snmp/disk_hw.c	2012-01-27 09:51:54.000000000 -0500
@@ -137,6 +137,7 @@
   if (disks) {
      free( disks );
      disks = NULL;
+     maxdisks = numdisks = 0;
   }
   allDisksIncluded = 0;
 }
