--- agent/mibgroup/ucd-snmp/disk_hw.c.orig	2011-09-06 22:38:43.000000000 -0300
+++ agent/mibgroup/ucd-snmp/disk_hw.c	2011-09-06 22:40:13.000000000 -0300
@@ -245,7 +245,7 @@
 
 
 static int _percent( int value, int total ) {
-    return (int)( value * 100 ) / total;
+    return (int)( value / (total / 100));
 }
 
 static netsnmp_fsys_info **
