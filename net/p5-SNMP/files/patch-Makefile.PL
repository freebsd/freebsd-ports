--- Makefile.PL	Mon Jan  8 19:58:04 2001
+++ Makefile.PL.orig	Sat Feb  5 08:09:39 2000
@@ -27,7 +27,7 @@
 	$snmp_link_lib = 'libsnmp';
 	$sep = '\\';
     } else {
-	$snmp_lib = 'libsnmp.a';
+	$snmp_lib = 'libsnmp.so';
 	$snmp_link_lib = 'snmp';
 	$sep = '/';
     }
