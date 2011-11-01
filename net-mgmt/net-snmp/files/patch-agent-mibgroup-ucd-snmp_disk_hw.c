--- agent/mibgroup/ucd-snmp/disk_hw.c.orig	2011-07-02 00:35:46.000000000 +0200
+++ agent/mibgroup/ucd-snmp/disk_hw.c	2011-10-06 19:17:46.000000000 +0200
@@ -245,7 +245,9 @@
 
 
 static int _percent( int value, int total ) {
-    return (int)( value * 100 ) / total;
+    if (!total)
+	return 100;
+    return (int)(( (int64_t) value * 100 ) / total);
 }
 
 static netsnmp_fsys_info **
