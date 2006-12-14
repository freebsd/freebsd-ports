--- ifstatus.cgi.orig	Thu Dec 14 00:39:56 2006
+++ ifstatus.cgi	Thu Dec 14 00:41:44 2006
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!%%LOCALBASE%%/bin/speedy -- -M20 -t3600 -gnone -r500
 # vim:ts=4
 # ifstatus.pl v1.0
 #
@@ -27,7 +27,7 @@
 my($VERSION) = "v1.0";
 
 # Variables
-my( $conffile ) = '/u01/etc/routers2.conf';
+my( $conffile ) = '%%LOCALBASE%%/etc/routers2.conf';
 
 my( $device, $community, $targetwindow, $target, $file, $backurl, $ifno )
 	= ( "","","graph","","","","");
