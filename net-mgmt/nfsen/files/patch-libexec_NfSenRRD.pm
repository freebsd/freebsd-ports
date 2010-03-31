--- libexec/NfSenRRD.pm.orig	2010-03-23 15:58:24.953252437 +0000
+++ libexec/NfSenRRD.pm	2010-03-23 15:58:35.624042719 +0000
@@ -73,7 +73,7 @@
 	if ( $rrd_version < 1.1 ) { # it's RRD 1.0.x
 		$RRDoffset = 77;
 	}
-	if ( $rrd_version >= 1.2 && $rrd_version < 1.4 ) {
+	if ( $rrd_version >= 1.2 && $rrd_version < 1.5 ) {
 		$RRDoffset = 67;
 	}
 
