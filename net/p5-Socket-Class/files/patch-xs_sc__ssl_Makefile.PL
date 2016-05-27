--- xs/sc_ssl/Makefile.PL.orig	2012-01-20 00:08:58 UTC
+++ xs/sc_ssl/Makefile.PL
@@ -171,7 +171,7 @@ sub build_cmodule {
 	$step = 0;
 	foreach( <$fh> ) {
 		if( $step == 0 ) {
-			if( /\s*struct st_mod_sc {/ ) {
+			if( /\s*struct st_mod_sc \{/ ) {
 				$ct1 = index( $ct, '/* !include st_mod_sc */' );
 				$ct2 = substr( $ct, $ct1 + 25 );
 				$ct1 = substr( $ct, 0, $ct1 );
