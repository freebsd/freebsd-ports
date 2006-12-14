--- showcfg.cgi.orig	Thu Dec 14 00:58:09 2006
+++ showcfg.cgi	Thu Dec 14 00:58:54 2006
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!%%LOCALBASE%%/bin/speedy -- -M20 -t3600 -gnone -r500
 #
 # showcfg.cgi
 #
@@ -11,7 +11,7 @@
 use CGI;
 
 # Variables
-my( $confpath ) = "/home/stevesh/public_html/mrtg/conf/";
+my( $confpath ) = "%%LOCALBASE%%/etc/mrtg/";
 my( $device, $community, $targetwindow, $target, $file, $backurl )
 	= ( "","public","graph","","","");
 my( $conffile );
