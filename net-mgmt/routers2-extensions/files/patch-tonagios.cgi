--- tonagios.cgi.orig	2008-11-06 11:51:08.000000000 +0100
+++ tonagios.cgi	2008-11-06 11:51:45.000000000 +0100
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
 # This is chopped from the end of the configuration filename
 my( $TRUNCATE ) = "\.(cfg|conf)?";
 # Alternative examples
