--- Makefile.PL.orig	Sat May  4 14:25:20 2002
+++ Makefile.PL	Sat May  4 14:25:23 2002
@@ -10,6 +10,7 @@
 #
 
 $flavor=`uname`;
+chop $flavor;
 if (-e "/etc/mandrake-release") {$flavor="Mandrake";}
 
 if ($flavor eq "FreeBSD") { $thechoice="/usr/local/sbin/httpd"; 
