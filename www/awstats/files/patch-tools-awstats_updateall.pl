--- tools/awstats_updateall.pl.orig	2015-07-21 07:55:55 UTC
+++ tools/awstats_updateall.pl
@@ -129,8 +129,8 @@
 	# Check if AWSTATS prog is found
 	my $AwstatsFound=0;
 	if (-s "$Awstats") { $AwstatsFound=1; }
-	elsif (-s "/usr/local/awstats/wwwroot/cgi-bin/awstats.pl") {
-		$Awstats="/usr/local/awstats/wwwroot/cgi-bin/awstats.pl";
+	elsif (-s "%%PREFIX%%/www/awstats/cgi-bin/awstats.pl") {
+		$Awstats="%%PREFIX%%/www/awstats/cgi-bin/awstats.pl";
 		$AwstatsFound=1;
 	}
 	if (! $AwstatsFound) {
