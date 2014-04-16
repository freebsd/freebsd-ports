--- ./plugins-scripts/check_ntp.pl.orig	2014-03-04 20:21:36.000000000 +0100
+++ ./plugins-scripts/check_ntp.pl	2014-04-14 10:22:50.000000000 +0200
@@ -313,7 +313,6 @@
 				}
 			} else {
 				print "No match!\n" if $verbose;
-				$jitter = '(not parsed)';
 			}
 			
 		}
@@ -427,7 +426,7 @@
 foreach my $key (keys %ERRORS) {
 	if ($state==$ERRORS{$key}) {
 #		print ("NTP $key: $answer");
-		print ("NTP $key: $answer|offset=$offset, jitter=" . $jitter/1000 .	",peer_stratum=$stratum\n");
+		print ("NTP $key: $answer|offset=$offset, jitter=" . ($jitter || 0)/1000 .	",peer_stratum=$stratum\n");
 		last;
 	}
 }
