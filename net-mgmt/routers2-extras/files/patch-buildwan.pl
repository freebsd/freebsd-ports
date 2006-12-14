--- buildwan.pl.orig	Fri Jun 16 00:17:53 2006
+++ buildwan.pl	Thu Dec 14 15:41:08 2006
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!%%PERL%%
 #
 # Try to build configuration files for all the routers in the WAN,
 # by recursively scanning them.  Can take a long time to run!
@@ -16,7 +16,7 @@
 use strict;
 use Net::SNMP;
 use FileHandle;
-use vars qw($opt_L $opt_h $opt_s $opt_c $opt_D $opt_w $opt_N $opt_A);
+use vars qw($opt_L $opt_h $opt_s $opt_c $opt_D $opt_w $opt_N $opt_A $opt_p);
 use Getopt::Std;
 
 my( $conffile, %config,@cfgfiles, $pathsep );
@@ -32,7 +32,12 @@
 my($IPIFINDEX) = "1.3.6.1.2.1.4.20.1.2";
 my($IPROUTEGW) = "1.3.6.1.2.1.4.21.1.7";
 my($CPUOID) = "1.3.6.1.4.1.9.2.1.58.0";
+my($FNDRYCPUOID) = "1.3.6.1.4.1.1991.1.1.2.1.35.0";
 my($MEMOID) = "1.3.6.1.4.1.9.9.48.1.1.1.5.1"; # have to find out
+my($FNDRYMEMOID) = "1.3.6.1.4.1.1991.1.1.2.1.55.0"; 
+my($FNDRYMAXMEMOID) = "1.3.6.1.4.1.1991.1.1.2.1.54.0"; 
+my($FNDRYBGPOID) = "1.3.6.1.4.1.1991.1.2.11.1.27.0"; 
+my($FNDRYTEMPOID) = "1.3.6.1.4.1.1991.1.1.1.1.18.0"; 
 # Cisco 7200 Series Temperature
 my($CISCOTEMP) = "1.3.6.1.4.1.9.9.13.1.3.1";
 
@@ -47,7 +52,8 @@
 my( $domain ) = "...\.adsw\.com";
 my( @community ) = ( "public" );
 my( $community );
-my( $workdir ) = "/var/rrdtool/auto";
+my( $workdir ) = "/var/db/rrdtool";
+my( $pathadd ) = "/usr/local/bin";
 my( @queue ) = ( );
 my( $subdir ) = "";
 my( @filelist ) = ();
@@ -80,8 +86,9 @@
 {
 	my($snmp, $resp, $snmperr, $k);
 	my($n,$v,$ip);
-	my($cpuok,$memok) ;
+	my($cpuok,$memok,$bgpok,$tempok);
 	my($rcomm) = "";
+	my($fndrymaxmem);
 	
 	$router = $_[0];
 	$cpuok = $memok = "";
@@ -268,15 +275,48 @@
 	$routerhostname = $routerip if(!$routerhostname);
 
 	# now check to see if the router has an OID for CPU and mem 
-	$resp = $snmp->get_request( $CPUOID, $MEMOID );
+	$resp = $snmp->get_request( $MEMOID );
 	if( $resp ) {
-		$cpuok = $CPUOID if( $resp->{$CPUOID} );
 		$memok = $MEMOID if( $resp->{$MEMOID} );
+	} else {
+		$resp = $snmp->get_request( $FNDRYMEMOID );
+		if( $resp ) {
+			$memok = $FNDRYMEMOID if( $resp->{$FNDRYMEMOID} );
+			$resp = $snmp->get_request( $FNDRYMAXMEMOID );
+			if( $resp ) {
+				$fndrymaxmem = $resp->{$FNDRYMAXMEMOID} if( $resp->{$FNDRYMAXMEMOID} );
+			}
+		}
 	}
 
+	# Try $CPUOID, if this doesn't work, try Foundry one
+	$resp = $snmp->get_request( $CPUOID );
+	if( $resp ) {
+		$cpuok = $CPUOID if( $resp->{$CPUOID} );
+	} else {
+		$resp = $snmp->get_request( $FNDRYCPUOID );
+		if( $resp ) {
+			$cpuok = $FNDRYCPUOID if( $resp->{$FNDRYCPUOID} );
+		}
+	}
+
+	# Try to check if BGP routes exists
+	$resp = $snmp->get_request( $FNDRYBGPOID );
+	if( $resp ) {
+		$bgpok = $FNDRYBGPOID if( $resp->{$FNDRYBGPOID} );
+	}
+
+	# Try to check if router has temp sensors (currently only foundry !)
+	$resp = $snmp->get_request( $FNDRYTEMPOID );
+	if( $resp ) {
+		$tempok = $FNDRYTEMPOID if( $resp->{$FNDRYTEMPOID} );
+	}
+
+
 	$routers{$router} = { interfaces=>{%interfaces}, name=>$routerdesc,
 		ip=>$routerip, hostname=>$routerhostname, community=>$rcomm,
-		cpu=>$cpuok, mem=>$memok };
+		cpu=>$cpuok, mem=>$memok, fndrymaxmem=>$fndrymaxmem,
+		bgp=>$bgpok, temp=>$tempok };
 
 	print "\rFinished router $routerhostname at address $routerip\n";
 
@@ -332,15 +372,20 @@
 	my($k,$nextip,$icon);
 	my($t,$d,$f);
 	my($mb,$pfx);
+	my $descr;
 
 	$n = ucfirst $n if($n !~ /\./);
 
 	foreach $k ( keys %$ifp ) {
+		my $descr;
+		$descr = $ifp->{$k}->{descr};
+		$descr =~ s/\n//g;
 		$icon = "interface-sm.gif";
 		$pfx = "";
 		$d = "";
 		$t = $h.".".$k;
-		$t = $h.".".$ifp->{$k}->{descr} if($ifp->{$k}->{descr});
+		#$t = $h.".".$ifp->{$k}->{descr} if($ifp->{$k}->{descr});
+		$t = $h.".".$descr if($descr);
 		$t =~ s/[\[\]#\/\\\s]+/./g;
 		$t =~ s/\.+/./g;
 		$t = lc $t;
@@ -349,7 +394,7 @@
 		if(!$ifp->{$k}->{speed} or !$c or !$h) {
 			$pfx = "# ";
 		}
-		if(!$includelans and $ifp->{$k}->{descr} =~ /(ether|token)/i) {
+		if(!$includelans and $descr =~ /(ether|token)/i) {
 			$pfx = "# ";
 		}
 #		print "$k".$ifp->{$k}{state}.": ".$ifp->{$k}{descr}
@@ -388,10 +433,10 @@
 
 		print CFG $pfx."Title[".$t."]: $n";
 		print CFG " (".$ifp->{$k}->{ip}.")" if($ifp->{$k}->{ip});
-		print CFG ": ".$ifp->{$k}->{descr}." $d\n";
+		print CFG ": ".$descr." $d\n";
 		print CFG $pfx."PageTop[".$t."]: <H1>Traffic analysis for "
-			.$ifp->{$k}->{descr}."</H1>\n";
-		print CFG $pfx."SetEnv[".$t."]: MRTG_INT_DESCR=\"".$ifp->{$k}->{descr}
+			.$descr."</H1>\n";
+		print CFG $pfx."SetEnv[".$t."]: MRTG_INT_DESCR=\"".$descr
 			."\" MRTG_INT_IP=\"".$ifp->{$k}->{ip}."\"\n";
 		if($mb > 1000000) {
 			print CFG $pfx."routers.cgi*UnScaled[$t]: none\n" 
@@ -408,7 +453,7 @@
 	.$ifp->{$k}->{destination}[2]." router-sm.gif\n";
 		}
 		print CFG $pfx."routers.cgi*ShortDesc[$t]: "
-			.$ifp->{$k}->{descr}." (".(ucfirst $ifp->{$k}->{destination}[0])
+			.$descr." (".(ucfirst $ifp->{$k}->{destination}[0])
 			.")\n"
 		if( $ifp->{$k}->{destination}[0]
 #			and ($ifp->{$k}->{destination}[0] !~ /^\d/i) 
@@ -431,7 +476,8 @@
 	open CFG, ">$fname";
 	print CFG "# MRTG config for router ".$routers{$rk}{hostname}
 		." community ".$routers{$rk}{community}
-		."\n\nWorkdir: $workdir\nLogformat: rrdtool\nOptions[_]: growright bits \n";
+		."\n\nWorkdir: $workdir\n"
+		."PathAdd: $pathadd\nLogformat: rrdtool\nOptions[_]: growright bits \n";
 	
 	print CFG "routers.cgi*Icon: router-sm.gif\n"
 		."routers.cgi*ShortDesc: ".$routers{$rk}{name}."\n\n";
@@ -451,6 +497,7 @@
 		.$routers{$rk}{name}." CPU Load\n";
 	print CFG "PageTop[".$routers{$rk}{hostname}.".CPU]: CPU Stats\n";
 	print CFG "routers.cgi*Mode[".$routers{$rk}{hostname}.".CPU]: cpu\n";
+	print CFG "routers.cgi*UnScaled[".$routers{$rk}{hostname}.".CPU]: none\n";
 	print CFG "routers.cgi*ShortDesc[".$routers{$rk}{hostname}
 		.".CPU]: CPU Stats\n";
 	} else {
@@ -461,7 +508,11 @@
 	print CFG "Target[".$routers{$rk}{hostname}.".MEM]: "
 		.$routers{$rk}{mem}."&".$routers{$rk}{mem}.":"
 		.$routers{$rk}{community}."\@".$routers{$rk}{hostname}."\n";
-	print CFG "MaxBytes[".$routers{$rk}{hostname}.".MEM]: 64000000\n";
+	if( $routers{$rk}{mem} == $FNDRYMEMOID ) {
+		print CFG "MaxBytes[".$routers{$rk}{hostname}.".MEM]: ".$routers{$rk}{fndrymaxmem}."\n";
+	} else {
+		print CFG "MaxBytes[".$routers{$rk}{hostname}.".MEM]: 64000000\n";
+	}
 	print CFG "Options[".$routers{$rk}{hostname}.".MEM]: "
 		."nopercent integer gauge noo\n";
 	print CFG "routers.cgi*UnScaled[".$routers{$rk}{hostname}.".MEM]: none\n";
@@ -480,6 +531,61 @@
 	} else {
 		print CFG "# Unable to identify a Memory usage OID in MIB\n";
 	}
+
+	if( $routers{$rk}{bgp} ) {
+	print CFG "# BGP routes\n";
+	print CFG "Target[".$routers{$rk}{hostname}.".BGP]: "
+		.$routers{$rk}{bgp}."&".$routers{$rk}{bgp}.":"
+		.$routers{$rk}{community}."\@".$routers{$rk}{hostname}."\n";
+	print CFG "MaxBytes[".$routers{$rk}{hostname}.".BGP]: 100000000\n";
+	print CFG "Options[".$routers{$rk}{hostname}.".BGP]: "
+		."absolute nopercent integer gauge noo\n";
+	print CFG "routers.cgi*UnScaled[".$routers{$rk}{hostname}.".BGP]: none\n";
+	print CFG "Title[".$routers{$rk}{hostname}.".BGP]: "
+		.$routers{$rk}{name}." Total BGP routes\n";
+	print CFG "ShortLegend[".$routers{$rk}{hostname}.".BGP]: Routes\n";
+	print CFG "YLegend[".$routers{$rk}{hostname}.".BGP]: BGP Routes\n";
+	print CFG "PageTop[".$routers{$rk}{hostname}.".BGP]: Total BGP Routes\n";
+	print CFG "LegendI[".$routers{$rk}{hostname}.".BGP]: Routes:\n";
+	print CFG "Legend1[".$routers{$rk}{hostname}.".BGP]: Routes\n";
+	print CFG "Legend3[".$routers{$rk}{hostname}.".BGP]: Peak Routes\n";
+	print CFG "routers.cgi*ShortDesc[".$routers{$rk}{hostname}
+		.".BGP]: BGP Routes\n";
+	print CFG "routers.cgi*Options[".$routers{$rk}{hostname}
+		.".BGP]: noo, nopercent, absolute, nototal, nopercentile\n";
+	} else {
+		print CFG "# No BGP routes OID in MIB\n";
+	}
+
+	if( $routers{$rk}{temp} ) {
+	print CFG "# Temperature\n";
+	# Warning Foundry OID is temperature * 2, so we have to divide it by 2
+	print CFG "Target[".$routers{$rk}{hostname}.".TEMP]: "
+		.$routers{$rk}{temp}."&".$routers{$rk}{temp}.":"
+		.$routers{$rk}{community}."\@".$routers{$rk}{hostname}." / 2\n";
+	# 100°C is sufficient to handle this. At this temperature, we can think
+	#       that router ... near to die.
+	print CFG "MaxBytes[".$routers{$rk}{hostname}.".TEMP]: 100\n";
+	print CFG "Options[".$routers{$rk}{hostname}.".TEMP]: "
+		."absolute nopercent gauge noo\n";
+	print CFG "routers.cgi*UnScaled[".$routers{$rk}{hostname}.".TEMP]: none\n";
+	print CFG "Title[".$routers{$rk}{hostname}.".TEMP]: "
+		.$routers{$rk}{name}." Temperature\n";
+	print CFG "ShortLegend[".$routers{$rk}{hostname}.".TEMP]: °C\n";
+	print CFG "PageTop[".$routers{$rk}{hostname}.".TEMP]: Temperature\n";
+	print CFG "LegendI[".$routers{$rk}{hostname}.".TEMP]: Temperature\n";
+	print CFG "Legend1[".$routers{$rk}{hostname}.".TEMP]: Temperature\n";
+	print CFG "Legend3[".$routers{$rk}{hostname}.".TEMP]: Peak Temperature\n";
+	print CFG "routers.cgi*ShortDesc[".$routers{$rk}{hostname}
+		.".TEMP]: Temperature\n";
+	print CFG "routers.cgi*Options[".$routers{$rk}{hostname}
+		.".TEMP]: noo, nopercent, absolute, nototal, nopercentile\n";
+	print CFG "routers.cgi*Icon[".$routers{$rk}{hostname}
+		.".TEMP]: temp-sm.gif\n";
+	} else {
+		print CFG "# No Temperature OID in MIB\n";
+	}
+
 	
 	close CFG;
 
@@ -495,10 +601,10 @@
 	$script = "/cgi-bin/routers2.pl";
 }
 
-getopts('hc:D:s:Lw:NA');
+getopts('hc:D:s:Lw:NAp:');
 
 if($opt_h or $#ARGV<0) {
-	print "Usage: buildwan -h\n       buildwan [-L][-A][-N][-s <subdir>][-c <communitylist>][-D <domainname>] -w <workdir> <router>...\n";
+	print "Usage: buildwan -h\n       buildwan [-L][-A][-N][-s <subdir>][-c <communitylist>][-D <domainname>] -w <workdir> -p <rrdpath> <router>...\n";
 	print "-L: Include ethernet/token ring Lan interfaces\n";
 	print "-A: Include ethernet/token ring Lan interfaces even if they are down\n";
 	print "-N: Don't browse network neighors.\n";
@@ -506,6 +612,7 @@
 	print "-D: Specify domain name to be stripped from hostnames in descriptions\n";
 	print "-c: Specify SNMP community string (default is 'public'), separate with commas\n";
 	print "-w: Specify Work directory where the .rrd files go.\n";
+	print "-p: Specify the rddtool path (default is /usr/local/bin).\n";
 	
 	exit 1;
 }
@@ -515,6 +622,7 @@
 $includelans = 1 if($opt_L);
 $includealllan = 1 if($opt_A);
 $workdir = $opt_w if($opt_w);
+$pathadd = $opt_p if($opt_p);
 @community = split /,\s*/,$opt_c if($opt_c); 
 @community = ( 'public' ) if(!@community);
 if($opt_D) {
