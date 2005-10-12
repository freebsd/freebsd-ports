--- lib/POE/Component/Server/SimpleHTTP.pm.orig	Wed Oct 12 14:07:14 2005
+++ lib/POE/Component/Server/SimpleHTTP.pm	Wed Oct 12 14:08:57 2005
@@ -542,7 +542,7 @@
 		}
 
 		# Destroy this wheel!
-		delete $_[HEAP]->{'REQUESTS'}->{ $id }->[0];
+		$_[HEAP]->{'REQUESTS'}->{ $id }->[0] = undef;
 		delete $_[HEAP]->{'REQUESTS'}->{ $id };
 
 		# All done!
@@ -614,7 +614,7 @@
 	# Check if the SimpleHTTP::Connection object croaked ( happens when sockets just disappear )
 	if ( ! defined $response->{'CONNECTION'} ) {
 		# Destroy this wheel!
-		delete $_[HEAP]->{'REQUESTS'}->{ $id }->[0];
+		$_[HEAP]->{'REQUESTS'}->{ $id }->[0] = undef;
 		delete $_[HEAP]->{'REQUESTS'}->{ $id };
 
 		# All done!
@@ -671,7 +671,7 @@
 
 		# Delete the wheel
 		# Tracked down by Paul Visscher
-		delete $_[HEAP]->{'REQUESTS'}->{ $id }->[0];
+		$_[HEAP]->{'REQUESTS'}->{ $id }->[0] = undef;
 		delete $_[HEAP]->{'REQUESTS'}->{ $id };
 	} else {
 		# Ignore this, eh?
@@ -823,7 +823,7 @@
 	}
 
 	# Delete it!
-	delete $_[HEAP]->{'REQUESTS'}->{ $id }->[0];
+	$_[HEAP]->{'REQUESTS'}->{ $id }->[0] = undef;
 	delete $_[HEAP]->{'REQUESTS'}->{ $id };
 
 	# All done!
