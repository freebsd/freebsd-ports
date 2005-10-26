--- tools/awstats_updateall.pl.orig	Mon Jun  7 08:27:26 2004
+++ tools/awstats_updateall.pl	Thu Sep 22 01:30:15 2005
@@ -121,8 +121,8 @@
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
