--- drraw.cgi.orig	Mon Jul 24 13:30:01 2006
+++ drraw.cgi	Mon Jul 24 13:31:42 2006
@@ -49,7 +49,7 @@
 
 # The configuration file is expected to be found in the same directory
 # as drraw itself.  You may customize this to be elsewhere.
-my $config = (dirname($0) =~ /(.*)/)[0] . "/drraw.conf"; # Untaint
+my $config = '%%CONFDIR%%/drraw.conf'; # Untaint
 
 ###############################################################################
 ##   STOP STOP STOP STOP STOP STOP STOP STOP STOP STOP STOP STOP STOP STOP   ##
