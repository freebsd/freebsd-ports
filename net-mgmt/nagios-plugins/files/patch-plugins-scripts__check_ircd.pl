--- plugins-scripts/check_ircd.pl.orig	2014-03-04 21:41:57 UTC
+++ plugins-scripts/check_ircd.pl
@@ -66,6 +66,7 @@
 $ENV{PATH} = "";
 $ENV{ENV} = "";
 $ENV{BASH_ENV} = "";
+$ENV{CDPATH} = "";
 
 # -----------------------------------------------------------------[ Global ]--
 
@@ -153,7 +154,7 @@
 	    print "IRCD UNKNOWN: Could not start socket ($!)\n";
 	    exit $ERRORS{"UNKNOWN"};
 	}
-	$sockaddr = 'S n a4 x8';
+	$sockaddr = 'x C n a4 x8';
 	$that = pack($sockaddr, AF_INET, $in_remoteport, $thataddr);
 	if (!connect(ClientSocket, $that)) { 
 	    print "IRCD UNKNOWN: Could not connect socket ($!)\n";
