--- ./plugins-scripts/check_ircd.pl.orig	2014-04-27 19:59:06.000000000 +0200
+++ ./plugins-scripts/check_ircd.pl	2014-05-09 18:45:31.000000000 +0200
@@ -65,6 +65,7 @@
 $ENV{'PATH'}='@TRUSTED_PATH@';
 $ENV{'BASH_ENV'}=''; 
 $ENV{'ENV'}='';
+$ENV{CDPATH} = "";
 
 # -----------------------------------------------------------------[ Global ]--
 
@@ -152,7 +153,7 @@
 	    print "IRCD UNKNOWN: Could not start socket ($!)\n";
 	    exit $ERRORS{"UNKNOWN"};
 	}
-	$sockaddr = 'S n a4 x8';
+	$sockaddr = 'x C n a4 x8';
 	$that = pack($sockaddr, AF_INET, $in_remoteport, $thataddr);
 	if (!connect(ClientSocket, $that)) { 
 	    print "IRCD UNKNOWN: Could not connect socket ($!)\n";
