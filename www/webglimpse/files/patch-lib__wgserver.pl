--- ./lib/wgserver.pl.orig	1998-06-29 12:45:06.000000000 -0400
+++ ./lib/wgserver.pl	2009-07-07 22:30:26.508066485 -0400
@@ -114,6 +114,7 @@
 
 	$override = 0;
 	$ServerRoot = '';
+	$output = '';
 	
 	while (<CONF>)	{
 		# Trim leading white space 
@@ -163,8 +164,8 @@
 
 	close(CONF);
 
-	($ServerRoot ne '') && ($ResourceConfig = $ServerRoot.'/'.$ResourceConfig);	
-	($ServerRoot ne '') && ($AccessConfig = $ServerRoot.'/'.$AccessConfig);	
+	($ServerRoot ne '') && ($ResourceConfig ne '') && ($ResourceConfig !~ '^/') && ($ResourceConfig = $ServerRoot.'/'.$ResourceConfig);
+	($ServerRoot ne '') && ($AccessConfig ne '') && ($AccessConfig !~ '^/') && ($AccessConfig = $ServerRoot.'/'.$AccessConfig);
 
 	return $output;
 }
