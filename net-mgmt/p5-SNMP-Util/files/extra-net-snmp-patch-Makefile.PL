--- Makefile.PL.orig	Tue Jun 27 19:40:11 2000
+++ Makefile.PL	Thu May 20 14:04:59 2004
@@ -1,13 +1,13 @@
 use ExtUtils::MakeMaker;
 use FileHandle;
 
-print "Checking for SNMP, V1.8  ";
+print "Checking for SNMP, V5.1  ";
 $@ = '';
-eval "use SNMP 1.8 ();";
+eval "use SNMP 5.1 ();";
 if ($@) {
     $ok = 0;
-    print("\nYou don't have installed the SNMP module, version 1.8 or",
+    print("\nYou don't have installed the SNMP module, version 5.1 or",
           " later.\n");
 } else {
     print "ok\n";
 }
