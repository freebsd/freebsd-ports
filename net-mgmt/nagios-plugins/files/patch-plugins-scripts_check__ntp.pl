--- plugins-scripts/check_ntp.pl.orig	2015-07-30 21:40:06 UTC
+++ plugins-scripts/check_ntp.pl
@@ -313,7 +313,6 @@ if ($have_ntpq) {
 				}
 			} else {
 				print "No match!\n" if $verbose;
-				$jitter = '(not parsed)';
 			}
 			
 		}
@@ -427,7 +426,7 @@ if ($ntpdate_error != $ERRORS{'OK'}) {
 foreach my $key (keys %ERRORS) {
 	if ($state==$ERRORS{$key}) {
 #		print ("NTP $key: $answer");
-		print ("NTP $key: $answer|offset=$offset, jitter=" . $jitter/1000 .	",peer_stratum=$stratum\n");
+		print ("NTP $key: $answer|offset=$offset, jitter=" . ($jitter || 0)/1000 .	",peer_stratum=$stratum\n");
 		last;
 	}
 }
