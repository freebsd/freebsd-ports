--- gotmail.pl.orig	Mon Jul 23 20:04:47 2001
+++ gotmail.pl	Sun Mar 31 19:47:52 2002
@@ -462,6 +462,8 @@
 	
 	if ($page =~ m/<meta(.*)content=\"(.*)url=(\S+)\">/i) {
 		$redirect_location = $3;
+	} elsif ($page =~ m/\w+\.location\.replace\s*\(\"([^\"]+)\"/i) {
+		$redirect_location = $1;
 	}
 
 	if ($redirect_location eq "")
@@ -577,6 +579,10 @@
 	if ($stripmboxheader)
 	{
  	    s/^From (.*)\n//;
+	}
+	else
+	{
+	    s/^From\s+(\S+)\s+(\w+),\s+(\d+)\s+(\w+)\s+(\d+)\s+(\d+:\d+:\d+)/From $1 $2 $4 $3 $6 $5/;
 	}
 
 	# Strip any HTML artifacts from the message body.
