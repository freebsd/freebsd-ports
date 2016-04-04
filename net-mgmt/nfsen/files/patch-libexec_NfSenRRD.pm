--- libexec/NfSenRRD.pm.orig	2016-03-07 15:51:47 UTC
+++ libexec/NfSenRRD.pm
@@ -73,7 +73,7 @@ sub GetRRDoffset {
 	if ( $rrd_version < 1.1 ) { # it's RRD 1.0.x
 		$RRDoffset = 77;
 	}
-	if ( $rrd_version >= 1.2 && $rrd_version < 1.5 ) {
+	if ( $rrd_version >= 1.2 ) {
 		$RRDoffset = 67;
 	}
 
