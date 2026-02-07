--- funclib.pl.orig	2004-07-07 00:20:09 UTC
+++ funclib.pl
@@ -51,7 +51,7 @@ sub getquota {
 	$IMAPERROR=$imap->{'Error'} unless (defined(@tmp) && scalar(@tmp) > 1);
 	return  unless (defined(@tmp) && scalar(@tmp) > 1);
 #recreate array and remove extra spaces - fixes array properly
-	@tmp=($tmp[3],$tmp[4],$tmp[5]);
+#	@tmp=($tmp[3],$tmp[4],$tmp[5]);
 	return @tmp;
        	
 }
