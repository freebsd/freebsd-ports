--- plugins-scripts/check_ntp.pl.orig	2019-12-04 21:53:08 UTC
+++ plugins-scripts/check_ntp.pl
@@ -314,7 +314,6 @@ if ($have_ntpq) {
 				}
 			} else {
 				print "No match!\n" if $verbose;
-				$jitter = '(not parsed)';
 			}
 			
 		}
@@ -429,7 +428,7 @@ foreach my $key (keys %ERRORS) {
 	if ($state==$ERRORS{$key}) {
 		print ("NTP $key: $answer|offset=$offset");
 		if ($have_ntpq) {
-			print (", jitter=" . $jitter/1000 .	",peer_stratum=$stratum");
+			print (", jitter=" . ($jitter || 0)/1000 .	",peer_stratum=$stratum");
 		}
 		print ("\n");
 		last;
