--- plugins-scripts/check_ntp.pl.orig	2016-08-01 16:27:46 UTC
+++ plugins-scripts/check_ntp.pl
@@ -314,7 +314,6 @@ if ($have_ntpq) {
 				}
 			} else {
 				print "No match!\n" if $verbose;
-				$jitter = '(not parsed)';
 			}
 			
 		}
@@ -428,7 +427,7 @@ if ($ntpdate_error != $ERRORS{'OK'}) {
 foreach my $key (keys %ERRORS) {
 	if ($state==$ERRORS{$key}) {
 #		print ("NTP $key: $answer");
-		print ("NTP $key: $answer|offset=$offset, jitter=" . $jitter/1000 .	",peer_stratum=$stratum\n");
+		print ("NTP $key: $answer|offset=$offset, jitter=" . ($jitter || 0)/1000 .	",peer_stratum=$stratum\n");
 		last;
 	}
 }
