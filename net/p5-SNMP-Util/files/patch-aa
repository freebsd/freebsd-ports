--- Makefile.PL.orig	Tue Sep  7 15:26:45 1999
+++ Makefile.PL	Tue Sep  7 15:27:02 1999
@@ -12,21 +12,6 @@
     print "ok\n";
 }
 
-$FILE = new FileHandle;
-open($FILE,">t/snmp.data");
-
-print "\nEnter the IP address of the Device: ";
-chomp($IP = <stdin>);
-
-print "Enter the SNMP community string: ";
-chomp($community = <stdin>);
-
-print $FILE "IP = $IP\n";
-print $FILE "community = $community\n";
-
-close $FILE;
-
-
 # See lib/ExtUtils/MakeMaker.pm for details of how to influence
 # the contents of the Makefile that is written.
 WriteMakefile(
