--- cfgmaker_host.pl.orig	Thu Dec 14 15:43:49 2006
+++ cfgmaker_host.pl	Thu Dec 14 15:44:43 2006
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!%%PERL%%
 #
 # Create a MRTG .cfg file for a given host.  Include routers.cgi
 # extensions.  Check for different SNMP options available.
@@ -34,7 +33,7 @@
 my($PS) = '/';
 my($TIMEOUT) = 4;
 my($RETRIES) = 2;
-my($pingprobe) = "/usr/local/bin/mrtg-ping-probe";
+my($pingprobe) = "%%LOCALBASE%%/bin/mrtg-ping-probe";
 
 $|=1;
 #######################################################################
@@ -78,12 +77,16 @@
 	netopiausedmem  => 'enterprises.304.1.3.1.3.6.0',
 	netopiacurcpu   => 'enterprises.304.1.3.1.3.1.0',
 	netopiaavgcpu   => 'enterprises.304.1.3.1.3.2.0',
-	# Fortynet
-	fortycpuusage	=> 'enterprises.12356.1.1.6.1.0',
-	fortycpuidle	=> 'enterprises.12356.1.1.6.2.0',
-	fortycpuint	=> 'enterprises.12356.1.1.6.3.0',
-	fortymemusage	=> 'enterprises.12356.1.1.6.4.0',
-	fortysessions	=> 'enterprises.12356.1.1.6.6.0',
+	# Fortinet MIB
+	forticpu	=> 'enterprises.12356.1.8.0',
+	fortimem	=> 'enterprises.12356.1.9.0',
+	fortisessions	=> 'enterprises.12356.1.10.0',
+#	fortycpuidle	=> 'enterprises.12356.1.1.6.2.0',
+#	fortycpuint	=> 'enterprises.12356.1.1.6.3.0',
+#	fortymemusage	=> 'enterprises.12356.1.1.6.4.0',
+#	fortysessions	=> 'enterprises.12356.1.1.6.6.0',
+	# Foundry MID
+	fndycpu		=> 'entreprises.1991.1.1.2.1.35.0',
 );
 
 #######################################################################
@@ -304,8 +307,74 @@
                 	print CFG "routers.cgi*Title[$hostname-CPU]: CPU Usage on $hostname\n";
                 	print CFG "routers.cgi*InSummary[$hostname-CPU]: yes\n";
 		} else {
-			print CFG "#\n# Not available.\n";
-			print "CPU usage statistics not available.\n";
+                	$rv = undef;
+                	($rv) = snmpget ($snmp, $OID{forticpu});
+                	if (defined $rv and ($rv > 0)) {
+                        	print "* CPU usage statistic available (FortiOS MIB).\n";
+                        	# Current CPU
+                        	print CFG "Target[$hostname-cpu-cur]: $OID{forticpu}&$OID{forticpu}:$snmp\n";
+                        	print CFG "PageTop[$hostname-cpu-cur]: $sdesc<BR>Current CPU usage\n";
+                        	print CFG "Title[$hostname-cpu-cur]: Current CPU on $sname\n";
+                        	print CFG "Maxbytes[$hostname-cpu-cur]: 100\n";
+                        	print CFG "Options[$hostname-cpu-cur]: gauge\n";
+                        	print CFG "YLegend[$hostname-cpu-cur]: percent\n";
+                        	print CFG "ShortLegend[$hostname-cpu-cur]: %\n";
+                        	print CFG "LegendI[$hostname-cpu-cur]: user:\n";
+                        	print CFG "Legend1[$hostname-cpu-cur]: Current CPU Usage\n";
+                        	print CFG "Legend3[$hostname-cpu-cur]: Current CPU Usage Peak\n";
+                        	print CFG "routers.cgi*WithPeak[$hostname-cpu-cur]: none\n";
+                        	print CFG "routers.cgi*Options[$hostname-cpu-cur]: noo, nopercent, nototal\n";
+                        	print CFG "routers.cgi*Graph[$hostname-cpu-cur]: $hostname-CPU \"CPU usage\" noo\n";
+                        	print CFG "routers.cgi*InMenu[$hostname-cpu-cur]: no\n";
+                        	print CFG "routers.cgi*InOut[$hostname-cpu-cur]: no\n";
+                        	print CFG "routers.cgi*InSummary[$hostname-cpu-cur]: no\n";
+                        	# Total & Graph
+                        	print CFG "routers.cgi*ShortName[$hostname-CPU]: CPU Utilisation\n";
+                        	print CFG "routers.cgi*Description[$hostname-CPU]: $hostname CPU Utilisation\n";
+                        	print CFG "routers.cgi*GraphStyle[$hostname-CPU]: normal\n";
+                        	print CFG "routers.cgi*Options[$hostname-CPU]: total, available\n";
+                        	print CFG "routers.cgi*LegendTI[$hostname-CPU]: Total usage\n";
+                        	print CFG "routers.cgi*MBLegend[$hostname-CPU]: 100% Utilisation\n";
+                        	print CFG "routers.cgi*Icon[$hostname-CPU]: cpu-sm.gif\n";
+                        	print CFG "routers.cgi*Title[$hostname-CPU]: CPU Usage on $hostname\n";
+                        	print CFG "routers.cgi*InSummary[$hostname-CPU]: yes\n";
+			} else {
+	                        $rv = undef;
+	                        ($rv) = snmpget ($snmp, $OID{fndrycpu});
+	                        if (defined $rv and ($rv > 0)) {
+	                                print "* CPU usage statistic available (Foundry MIB).\n";
+	                                # Current CPU
+	                                print CFG "Target[$hostname-cpu-cur]: $OID{fndrycpu}&$OID{fndrycpu}:$snmp\n";
+	                                print CFG "PageTop[$hostname-cpu-cur]: $sdesc<BR>Current CPU usage\n";
+	                                print CFG "Title[$hostname-cpu-cur]: Current CPU on $sname\n";
+	                                print CFG "Maxbytes[$hostname-cpu-cur]: 100\n";
+	                                print CFG "Options[$hostname-cpu-cur]: gauge\n";
+	                                print CFG "YLegend[$hostname-cpu-cur]: percent\n";
+	                                print CFG "ShortLegend[$hostname-cpu-cur]: %\n";
+	                                print CFG "LegendI[$hostname-cpu-cur]: user:\n";
+	                                print CFG "Legend1[$hostname-cpu-cur]: Current CPU Usage\n";
+	                                print CFG "Legend3[$hostname-cpu-cur]: Current CPU Usage Peak\n";
+	                                print CFG "routers.cgi*WithPeak[$hostname-cpu-cur]: none\n";
+	                                print CFG "routers.cgi*Options[$hostname-cpu-cur]: noo, nopercent, nototal\n";
+	                                print CFG "routers.cgi*Graph[$hostname-cpu-cur]: $hostname-CPU \"CPU usage\" noo\n";
+	                                print CFG "routers.cgi*InMenu[$hostname-cpu-cur]: no\n";
+  	                                print CFG "routers.cgi*InOut[$hostname-cpu-cur]: no\n";
+	                                print CFG "routers.cgi*InSummary[$hostname-cpu-cur]: no\n";
+                                	# Total & Graph
+                                	print CFG "routers.cgi*ShortName[$hostname-CPU]: CPU Utilisation\n";
+                                	print CFG "routers.cgi*Description[$hostname-CPU]: $hostname CPU Utilisation\n";
+                                	print CFG "routers.cgi*GraphStyle[$hostname-CPU]: normal\n";
+                                	print CFG "routers.cgi*Options[$hostname-CPU]: total, available\n";
+                                	print CFG "routers.cgi*LegendTI[$hostname-CPU]: Total usage\n";
+                                	print CFG "routers.cgi*MBLegend[$hostname-CPU]: 100% Utilisation\n";
+                                	print CFG "routers.cgi*Icon[$hostname-CPU]: cpu-sm.gif\n";
+                                	print CFG "routers.cgi*Title[$hostname-CPU]: CPU Usage on $hostname\n";
+                                	print CFG "routers.cgi*InSummary[$hostname-CPU]: yes\n";
+				} else {
+					print CFG "#\n# Not available.\n";
+					print "CPU usage statistics not available.\n";
+				}
+			}
 		}
 	}
 
@@ -313,6 +382,7 @@
 	# physical and virtual
 	print CFG "\n#######################################\n";
 	print CFG "# Memory used\n";
+	my $oldsname = $sname;	# To restore it later.
 	$rv = undef;
 	($rv) = snmpget($snmp, $OID{totalswap} );
 	if(defined $rv and ($rv > 0)) {
@@ -356,7 +426,21 @@
 					$targ = "$aroid&$asoid:$snmp";
 					$factor = 1;
 				} else {
-					print "Memory stats not available.\n";
+                               		$rv = undef;
+                                		($rv) = snmpget($snmp, $OID{fortimem} );
+                                		if ($rv>0) {
+                                        		print "* Memory utilisation available (FortiOS MIB).\n";
+                                        		#($mbr, $mbs) = snmpget($snmp, $OID{fortimem}, $OID{fortimem});
+							$mbr = 100;
+							$mbs = 100;;
+                                        		$aroid = $OID{fortimem};
+                                        		$asoid = $OID{fortimem};
+                                        		$targ = "$aroid&$asoid:$snmp";
+                                        		$factor = 1;
+							$sname = "$sname in % ";
+					} else {
+						print "Memory stats not available.\n";
+					}
 				}
 			}
 		}
@@ -441,6 +525,7 @@
 		print CFG "#\n# Not available.\n";
 		print "Paging statistics not available.\n";
 	}
+	$sname = $oldsname;
 
 	# Disk
 	# individual disk spaces, and one userdefined summary
@@ -622,6 +707,51 @@
 		print CFG "#\n# Not available.\n";
 		print "User count not available.\n";
 	}
+
+	# Sessions
+        print CFG "\n#######################################\n";
+        print CFG "# Session count\n";
+        $rv = undef;
+        $targ = "";
+        ($rv) = snmpget($snmp, $OID{fortisessions} );
+        if(defined $rv) {
+                print "* Session counter available (FortiOS MIB).\n";
+                $targ = "$OID{fortisessions}&$OID{fortisessions}:$snmp";
+
+#        } else {
+#                ($rv) = snmpget($snmp, $OID{sunusers} );
+#                if(defined $rv) {
+#                        print "* User counter available (Sun-MIB).\n";
+#                        $targ = "$OID{sunusers}&$OID{sunusers}:$snmp";
+#                }
+        }
+
+        if($targ) {
+                print CFG "Target[$hostname-sessions]: $targ\n";
+                print CFG "PageTop[$hostname-sessions]: $sdesc<BR>Active Sessions\n";
+                print CFG "Title[$hostname-sessions]: Active Sessions on $sname\n";
+                print CFG "MaxBytes[$hostname-sessions]: 1000000\n";
+                print CFG "SetEnv[$hostname-sessions]: MRTG_INT_DESCR=\"Sessions\"\n";
+                print CFG "Options[$hostname-sessions]: nopercent, gauge\n";
+                print CFG "YLegend[$hostname-sessions]: Sessions\n";
+                print CFG "ShortLegend[$hostname-sessions]: &nbsp;\n";
+                print CFG "LegendI[$hostname-sessions]: Sessions\n";
+                print CFG "Legend1[$hostname-sessions]: Active Sessions\n";
+                print CFG "Legend3[$hostname-sessions]: Peak Active Sessions\n";
+                print CFG "routers.cgi*Options[$hostname-sessions]: nomax, nototal, fixunit, noo\n";
+                print CFG "routers.cgi*Mode[$hostname-sessions]: general\n";
+                print CFG "routers.cgi*ShortDesc[$hostname-sessions]: Sessions\n";
+                print CFG "routers.cgi*Description[$hostname-sessions]: Sessions on $sname\n";
+                print CFG "routers.cgi*UnScaled[$hostname-sessions]: none\n";
+                print CFG "routers.cgi*InOut[$hostname-sessions]: no\n";
+                print CFG "routers.cgi*InSummary[$hostname-sessions]: yes\n";
+                print CFG "routers.cgi*InCompact[$hostname-sessions]: no\n";
+                print CFG "routers.cgi*Icon[$hostname-sessions]: user-sm.gif\n";
+        } else {
+                print CFG "#\n# Not available.\n";
+                print "Sessions count not available.\n";
+        }
+
 
 	# processes
 	print CFG "\n#######################################\n";
