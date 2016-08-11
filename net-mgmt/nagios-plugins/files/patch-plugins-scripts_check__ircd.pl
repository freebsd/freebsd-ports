--- plugins-scripts/check_ircd.pl.orig	2016-08-01 16:27:46 UTC
+++ plugins-scripts/check_ircd.pl
@@ -68,6 +68,7 @@ sub bindRemote ($$);
 $ENV{'PATH'}='@TRUSTED_PATH@';
 $ENV{'BASH_ENV'}=''; 
 $ENV{'ENV'}='';
+$ENV{'CDPATH'} = "";
 
 # -----------------------------------------------------------------[ Global ]--
 
@@ -155,7 +156,7 @@ sub bindRemote ($$)
 	    print "IRCD UNKNOWN: Could not start socket ($!)\n";
 	    exit $ERRORS{"UNKNOWN"};
 	}
-	$sockaddr = 'S n a4 x8';
+	$sockaddr = 'x C n a4 x8';
 	$that = pack($sockaddr, AF_INET, $in_remoteport, $thataddr);
 	if (!connect(ClientSocket, $that)) { 
 	    print "IRCD UNKNOWN: Could not connect socket ($!)\n";
