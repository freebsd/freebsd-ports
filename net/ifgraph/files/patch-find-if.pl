--- find-if.pl.orig	Sat Sep 20 14:35:38 2003
+++ find-if.pl	Sat Sep 20 14:36:07 2003
@@ -19,10 +19,6 @@
 #Sugestoes e criticas (sem flames!!) mailto:sartori@ifgraph.org
 #Visite: http://www.ifgraph.org
 
-# Let's find out where we are
-use FindBin;
-# # Found, now we add it to the @INC
-use lib "$FindBin::Bin/lib";
 # # We are strict
 use strict;
 # # Get the command line options
@@ -30,7 +26,7 @@
 getopts('adhims');
 
 # We just nedd the basic features here
-use Net::SNMP_365;
+use Net::SNMP;
 
 use vars qw($response $response2 $response3 $response4 $response5 $response6 $response7 $response8 $response9
 	    $response10 $response11 $response12 $opt_d @ips $ip $mac $opt_a $opt_h $opt_m $opt_i $opt_s $if $desc $stat $ocin
