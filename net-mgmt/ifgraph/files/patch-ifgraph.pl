--- ifgraph.pl.orig	Sat Jan  3 16:44:21 2004
+++ ifgraph.pl	Tue Feb  7 12:34:09 2006
@@ -19,10 +19,6 @@
 #Sugestoes e criticas (sem flames!!) mailto:sartori@ifgraph.lrv.ufsc.br
 #Visite: http://ifgraph.lrv.ufsc.br
 
-# Let's find out where we are
-use FindBin;
-# Found, now we add it to the @INC
-use lib "$FindBin::Bin/lib";
 # We are strict
 use strict;
 # Get the command line options
@@ -32,14 +28,7 @@
 getopt('cltF');
 getopts('dhT');
 
-# If the perl is older, we have to fetch the older Net::SNMP library
-if ($] < 5.006) { 
-	&debug("Warning: Older perl version $], we will use Net::SNMP 3.65\n");
-	require Net::SNMP_365; 
-} else {
-	&debug("Starting ifgraph 0.4.10 with perl $], Net::SNMP 4.3\n");
-	require Net::SNMP;
-}
+use Net::SNMP;
 
 # SIGINT call
 $SIG{INT}=\&sigint;
