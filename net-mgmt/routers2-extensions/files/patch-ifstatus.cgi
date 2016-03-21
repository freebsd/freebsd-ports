--- ifstatus.cgi.orig	2012-09-19 02:32:33 UTC
+++ ifstatus.cgi
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!%%LOCALBASE%%/bin/speedy -- -M20 -t3600 -gnone -r500
 # vim:ts=4
 # ifstatus.pl v1.0
 #
@@ -25,7 +25,7 @@ use Net::SNMP;
 my($VERSION) = "v1.0";
 
 # Variables
-my( $conffile ) = '/u01/etc/routers2.conf';
+my( $conffile ) = '%%LOCALBASE%%/etc/routers2.conf';
 
 my( $device, $community, $targetwindow, $target, $file, $backurl, $ifno )
 	= ( "","","graph","","","","");
