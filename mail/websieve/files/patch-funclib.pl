--- funclib.pl.orig	Mon Sep 24 14:50:50 2001
+++ funclib.pl	Wed Apr 23 19:24:59 2003
@@ -51,7 +51,7 @@
 	$IMAPERROR=$imap->{'Error'} unless (defined(@tmp) && scalar(@tmp) > 1);
 	return  unless (defined(@tmp) && scalar(@tmp) > 1);
 #recreate array and remove extra spaces - fixes array properly
-	@tmp=($tmp[3],$tmp[4],$tmp[5]);
+#	@tmp=($tmp[3],$tmp[4],$tmp[5]);
 	return @tmp;
        	
 }
