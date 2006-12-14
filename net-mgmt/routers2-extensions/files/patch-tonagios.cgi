--- tonagios.cgi.orig	Thu Dec 14 01:00:19 2006
+++ tonagios.cgi	Thu Dec 14 01:00:58 2006
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!%%LOCALBASE%%/bin/speedy -- -M20 -t3600 -gnone -r500
 #
 # tonagios.cgi
 #
@@ -8,7 +8,7 @@
 use CGI;
 
 # configure here: Nagios status.cgi URL (or use extinfo.cgi instead)
-my( $NAGIOS ) = "http://nagios.auckland.ac.nz/nagios/cgi-bin/status.cgi";
+my( $NAGIOS ) = "http://changeme/nagios/cgi-bin/status.cgi";
 
 # Variables
 my( $device, $community, $targetwindow, $target, $file, $backurl )
