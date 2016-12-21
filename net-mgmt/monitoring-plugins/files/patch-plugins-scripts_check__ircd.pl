--- plugins-scripts/check_ircd.pl.orig	2016-11-29 08:45:08 UTC
+++ plugins-scripts/check_ircd.pl
@@ -65,6 +65,7 @@ sub bindRemote ($$);
 $ENV{'PATH'}='@TRUSTED_PATH@';
 $ENV{'BASH_ENV'}=''; 
 $ENV{'ENV'}='';
+$ENV{CDPATH} = "";
 
 # -----------------------------------------------------------------[ Global ]--
 
@@ -152,7 +153,7 @@ sub bindRemote ($$)
 	    print "IRCD UNKNOWN: Could not start socket ($!)\n";
 	    exit $ERRORS{"UNKNOWN"};
 	}
-	$sockaddr = 'S n a4 x8';
+	$sockaddr = 'x C n a4 x8';
 	$that = pack($sockaddr, AF_INET, $in_remoteport, $thataddr);
 	if (!connect(ClientSocket, $that)) { 
 	    print "IRCD UNKNOWN: Could not connect socket ($!)\n";
