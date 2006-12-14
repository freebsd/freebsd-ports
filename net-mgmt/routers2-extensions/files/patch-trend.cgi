--- trend.cgi.orig	Thu Dec 14 01:07:06 2006
+++ trend.cgi	Thu Dec 14 01:08:21 2006
@@ -1,5 +1,4 @@
-#!/usr/bin/perl 
-##!/usr/bin/speedy 
+#!%%LOCALBASE%%/bin/speedy -- -M20 -t3600 -gnone -r500
 # vim:ts=4
 # trend.cgi
 #    Generate a trending graph, based on yearly data, for the specified
@@ -67,7 +66,7 @@
 my( $BASE    ) = 0; # 0=current, 1=average
 my( $device, $community, $targetwindow, $target, $file, $backurl )
 	= ( "","public","graph","","","");
-my( $conffile ) = "/u01/etc/routers2.conf"; # overridden by passed parameters
+my( $conffile ) = "%%LOCALBASE%%/etc/routers2.conf"; # overridden by passed parameters
 my( $routersurl ) = '';
 my( $q ) = new CGI;
 my( %headeropts ) = ();
