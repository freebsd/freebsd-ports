--- ../tnm/library/init.tcl.orig	Tue Sep 27 00:56:07 2005
+++ ../tnm/library/init.tcl	Tue Sep 27 00:57:30 2005
@@ -136,6 +136,9 @@
 lappend tnm(mibs) TUBS-IBR-NFS-MIB TUBS-IBR-PROC-MIB
 lappend tnm(mibs) TUBS-IBR-LINUX-MIB
 
+# Add also FreeBSD specific MIB
+lappend tnm(mibs) /usr/share/snmp/mibs/FREEBSD-MIB.txt
+
 # Define a proc to handle background errors if none exists. First try
 # to auto_load a definition so that we don't overwrite a definition
 # provided by another package.
