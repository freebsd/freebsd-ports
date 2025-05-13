--- Makefile.PL.orig	2025-05-11 19:09:26 UTC
+++ Makefile.PL
@@ -341,7 +341,7 @@ sub get_constants_headers
 
 	my @out;
 	foreach my $e (sort keys %syms) {
-		if ( $e =~ /(OBSOLETE|^CURL_DEPRECATED\z|^CURL_EXTERN|^CURL_IGNORE_DEPRECATION\z|^CURLOPTDEPRECATED\z|_LAST\z|_LASTENTRY\z|^CURL_FORMAT_OFF_T$|^CURL_ISOCPP$|^CURLOPT$)/ ) {
+		if ( $e =~ /(OBSOLETE|^CURL_DEPRECATED\z|^CURL_EXTERN|^CURL_IGNORE_DEPRECATION\z|^CURLOPTDEPRECATED\z|_LAST\z|_LASTENTRY\z|^CURL_FORMAT_OFF_T$|^CURL_ISOCPP$|^CURLOPT$|^CURL_HAS_)/ ) {
 			next;
 		}
 		push @out, $e;
