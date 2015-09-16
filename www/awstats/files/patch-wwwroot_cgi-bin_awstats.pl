--- wwwroot/cgi-bin/awstats.pl.orig	2015-06-18 14:35:12 UTC
+++ wwwroot/cgi-bin/awstats.pl
@@ -8983,12 +8983,12 @@ sub DefinePerlParsingFormat {
 		$LogFormatString =~ s/%>s/%code/g;
 		$LogFormatString =~ s/%b(\s)/%bytesd$1/g;
 		$LogFormatString =~ s/%b$/%bytesd/g;
-		$LogFormatString =~ s/\"%{Referer}i\"/%refererquot/g;
-		$LogFormatString =~ s/\"%{User-Agent}i\"/%uaquot/g;
-		$LogFormatString =~ s/%{mod_gzip_input_size}n/%gzipin/g;
-		$LogFormatString =~ s/%{mod_gzip_output_size}n/%gzipout/g;
-		$LogFormatString =~ s/%{mod_gzip_compression_ratio}n/%gzipratio/g;
-		$LogFormatString =~ s/\(%{ratio}n\)/%deflateratio/g;
+		$LogFormatString =~ s/\"%\{Referer\}i\"/%refererquot/g;
+		$LogFormatString =~ s/\"%\{User-Agent\}i\"/%uaquot/g;
+		$LogFormatString =~ s/%\{mod_gzip_input_size\}n/%gzipin/g;
+		$LogFormatString =~ s/%\{mod_gzip_output_size\}n/%gzipout/g;
+		$LogFormatString =~ s/%\{mod_gzip_compression_ratio\}n/%gzipratio/g;
+		$LogFormatString =~ s/\(%\{ratio\}n\)/%deflateratio/g;
 
 		# Replacement for a IIS and ISA format string
 		$LogFormatString =~ s/cs-uri-query/%query/g;    # Must be before cs-uri
