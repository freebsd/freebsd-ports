--- tools/awstats_updateall.pl.orig	Thu May 25 03:59:24 2006
+++ tools/awstats_updateall.pl	Sun Jul 16 01:14:54 2006
@@ -128,8 +128,8 @@
 	# Check if AWSTATS prog is found
 	my $AwstatsFound=0;
 	if (-s "$Awstats") { $AwstatsFound=1; }
-	elsif (-s "/usr/local/awstats/wwwroot/cgi-bin/awstats.pl") {
-		$Awstats="/usr/local/awstats/wwwroot/cgi-bin/awstats.pl";
+	elsif (-s "%%PREFIX%%/awstats/wwwroot/cgi-bin/awstats.pl") {
+		$Awstats="%%PREFIX%%/awstats/wwwroot/cgi-bin/awstats.pl";
 		$AwstatsFound=1;
 	}
 	if (! $AwstatsFound) {
