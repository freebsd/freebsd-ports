--- ./ifgraph.pl.orig	Sat Jan  3 23:44:21 2004
+++ ./ifgraph.pl	Mon Oct  9 13:49:17 2006
@@ -1,4 +1,4 @@
-#!/usr/bin/perl -w
+#!%%PERL%% -w
 #ifGraph 0.4.10 - Network Interface Data to RRD
 #Copyright (C) 2001-2003 Ricardo Sartori
 #
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
@@ -54,9 +43,9 @@
 if (defined($opt_c)) {
  $configfile=$opt_c;
 } else {
- print("Warning: searching /usr/local/etc/, /etc and ./ for an ifgraph.conf file\n");
- if (-r "/usr/local/etc/ifgraph.conf") { 
-  	$configfile="/usr/local/etc/ifgraph.conf";
+ print("Warning: searching %%PREFIX%%/etc/, /etc and ./ for an ifgraph.conf file\n");
+ if (-r "%%PREFIX%%/etc/ifgraph.conf") { 
+  	$configfile="%%PREFIX%%/etc/ifgraph.conf";
  } elsif (-r "/etc/ifgraph.conf") { # used from the patch of Iain Lea <iain@bricbrac.de>
   	$configfile="/etc/ifgraph.conf";
  } elsif (-r "./ifgraph.conf") {
@@ -804,7 +793,7 @@
  # Setting targets defaults
  my(@default)=("name","1G","localhost","public",161,0,1,0,10,600,300,"RRA:AVERAGE:0.5:1:600 RRA:AVERAGE:0.5:6:700 RRA:AVERAGE:0.5:24:775 RRA:AVERAGE:0.5:288:797 RRA:MAX:0.5:1:600 RRA:MAX:0.5:6:700 RRA:MAX:0.5:24:775 RRA:MAX:0.5:288:797",0,"GAUGE");
  # Setting global defaults
- @global[1,2,4]=("/usr/local/bin/rrdtool","/usr/local/rrdfiles/",1);
+ @global[1,2,4]=("%%LOCALBASE%%/bin/rrdtool","%%LOCALBASE%%/rrdfiles/",1);
  my($accept_new_target)=1;
  my($index)=-1; # $index replaces $global[0] during the parsing
  open(CONF,"$configfile") || die("readconf() Fatal: Could not read config file $configfile ($!)\n");
