--- makegraph.pl.orig	Sat Jan  3 16:44:21 2004
+++ makegraph.pl	Tue Feb  7 12:48:07 2006
@@ -19,8 +19,6 @@
 #Sugestoes e criticas (sem flames!!) mailto:sartori@ifgraph.lrv.ufsc.br
 #Visite: http://ifgraph.lrv.ufsc.br
 
-use FindBin;
-use lib "$FindBin::Bin/lib";
 use strict;
 use Getopt::Std;
 use Color::Rgb;
@@ -31,14 +29,7 @@
 getopt('ctT');
 getopts('Bbgdh');
 
-# If the perl is older, we have to fetch the older Net::SNMP library
-if ($] < 5.006) { 
-	&debug("Warning: Older perl version $], we will use Net::SNMP 3.65\n");
-	require Net::SNMP_365; 
-} else {
-	&debug("Starting ifgraph 0.4.10 with perl $[, Net::SNMP 4.3\n");
-	require Net::SNMP;
-}
+use Net::SNMP;
 
 # HELP
 if (defined($opt_h)) {
