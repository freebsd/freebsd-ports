--- libexec/NfSenRRD.pm.orig	2008-08-05 10:49:34.000000000 +0100
+++ libexec/NfSenRRD.pm	2008-08-05 10:50:13.000000000 +0100
@@ -73,7 +73,7 @@
 	if ( $rrd_version < 1.1 ) { # it's RRD 1.0.x
 		$RRDoffset = 77;
 	}
-	if ( $rrd_version >= 1.2 && $rrd_version < 1.3 ) {
+	if ( $rrd_version >= 1.2 && $rrd_version < 1.4 ) {
 		$RRDoffset = 67;
 	}
 
