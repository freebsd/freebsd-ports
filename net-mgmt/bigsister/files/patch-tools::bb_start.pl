--- tools/bb_start.pl.orig	Mon Aug 11 21:29:38 2003
+++ tools/bb_start.pl	Sat Feb 28 17:28:29 2004
@@ -161,7 +161,7 @@
 
 sub proclist {
     my @result;
-    foreach my $cmd ( "ps cax", "ps -e", "ps -ef" ) {
+    foreach my $cmd ( "/bin/ps ax" ) {
 	open( CMD, "$cmd 2>/dev/null|" );
 	@result = ();
 	while( <CMD> ) {
@@ -197,7 +197,7 @@
 	    exec( $cmd );
 	}
 	else {
-	    exec( "su", "-", "$user", "-c", $cmd );
+	    exec( "/usr/bin/su", "-m", "$user", "-c", $cmd );
 	}
 	exit(1);
     }
