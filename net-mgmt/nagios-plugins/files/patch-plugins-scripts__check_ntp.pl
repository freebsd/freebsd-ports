--- plugins-scripts/check_ntp.pl.orig	Wed Nov 30 11:19:47 2005
+++ plugins-scripts/check_ntp.pl	Fri May 12 23:39:15 2006
@@ -314,7 +314,6 @@
 				}
 			} else {
 				print "No match!\n" if $verbose;
-				$jitter = '(not parsed)';
 			}
 			
 		}
@@ -428,7 +427,7 @@
 foreach my $key (keys %ERRORS) {
 	if ($state==$ERRORS{$key}) {
 #		print ("NTP $key: $answer");
-		print ("NTP $key: $answer|offset=$offset, jitter=" . $jitter/1000 .	",peer_stratum=$stratum\n");
+		print ("NTP $key: $answer|offset=$offset, jitter=" . ($jitter || 0)/1000 .	",peer_stratum=$stratum\n");
 		last;
 	}
 }
