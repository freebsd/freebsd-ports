--- makegraph.pl.orig	Sun Sep 21 12:30:49 2003
+++ makegraph.pl	Sun Sep 21 12:32:08 2003
@@ -19,8 +19,6 @@
 #Sugestoes e criticas (sem flames!!) mailto:sartori@ifgraph.org
 #Visite: http://www.ifgraph.org
 
-use FindBin;
-use lib "$FindBin::Bin/lib";
 use strict;
 use Getopt::Std;
 use vars qw($opt_d $opt_c $opt_B $opt_b $opt_h $opt_g $opt_t $opt_T $targetindex
@@ -30,14 +28,7 @@
 getopt('ctT');
 getopts('Bbgdh');
 
-# If the perl is older, we have to fetch the older Net::SNMP library
-if ($] < 5.006) { 
-	&debug("Warning: Older perl version $], we will use Net::SNMP 3.65\n");
-	require Net::SNMP_365; 
-} else {
-	&debug("Starting ifgraph 0.4.9 with perl $[, Net::SNMP 4.3\n");
-	require Net::SNMP;
-}
+use Net::SNMP;
 
 # HELP
 if (defined($opt_h)) {
