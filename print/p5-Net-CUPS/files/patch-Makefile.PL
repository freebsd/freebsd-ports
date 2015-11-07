Fixes issue with the version check as mentioned upstream: 
https://rt.cpan.org/Public/Bug/Display.html?id=104237

--- Makefile.PL.orig	2015-10-27 12:05:43 UTC
+++ Makefile.PL
@@ -31,8 +31,10 @@ else
 
 my @version_parts = split( /\./, $version );
 
-if( ( $version_parts[1] < 2 ) ||
-	( ( $version_parts[1] == 2 ) && ( $version_parts[2] < 2 ) ) )
+if( 
+	( $version_parts[0] < 1 ) ||
+	( ( $version_parts[0] == 1 ) && ( $version_parts[1] < 2 ) ) || 
+	( ( $version_parts[0] == 1 ) && ( $version_parts[1] == 2 ) && ( $version_parts[2] < 2 ) ) )
 {
 	print "The version of the Common Unix Printing System installed\n";
 	print "on your system is too old for this module to work properly.\n";
