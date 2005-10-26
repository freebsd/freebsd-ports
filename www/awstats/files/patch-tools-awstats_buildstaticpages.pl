--- tools/awstats_buildstaticpages.pl.orig	Sun Feb 20 11:11:06 2005
+++ tools/awstats_buildstaticpages.pl	Thu Sep 22 20:33:32 2005
@@ -293,8 +293,8 @@
 # Check if AWSTATS prog is found
 my $AwstatsFound=0;
 if (-s "$Awstats") { $AwstatsFound=1; }
-elsif (-s "/usr/local/awstats/wwwroot/cgi-bin/awstats.pl") {
-	$Awstats="/usr/local/awstats/wwwroot/cgi-bin/awstats.pl";
+elsif (-s "%%PREFIX%%/www/awstats/cgi-bin/awstats.pl") {
+	$Awstats="%%PREFIX%%/www/awstats/cgi-bin/awstats.pl";
 	$AwstatsFound=1;
 }
 if (! $AwstatsFound) {
