--- ifgraph.pl.orig	Sun Sep 28 22:29:51 2003
+++ ifgraph.pl	Sun Sep 28 22:30:19 2003
@@ -19,10 +19,6 @@
 #Sugestoes e criticas (sem flames!!) mailto:sartori@ifgraph.org
 #Visite: http://www.ifgraph.org
 
-# Let's find out where we are
-use FindBin;
-# Found, now we add it to the @INC
-use lib "$FindBin::Bin/lib";
 # We are strict
 use strict;
 # Get the command line options
@@ -32,14 +28,7 @@
 getopt('cltF');
 getopts('dh');
 
-# If the perl is older, we have to fetch the older Net::SNMP library
-if ($] < 5.006) { 
-	&debug("Warning: Older perl version $], we will use Net::SNMP 3.65\n");
-	require Net::SNMP_365; 
-} else {
-	&debug("Starting ifgraph 0.4.9 with perl $], Net::SNMP 4.3\n");
-	require Net::SNMP;
-}
+use Net::SNMP;
 
 # SIGINT call
 $SIG{INT}=\&sigint;
