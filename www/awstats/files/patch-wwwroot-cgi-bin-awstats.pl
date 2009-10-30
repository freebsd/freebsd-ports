--- wwwroot/cgi-bin/awstats.pl.orig	2009-10-10 08:36:38.000000000 -0400
+++ wwwroot/cgi-bin/awstats.pl	2009-10-28 21:33:22.000000000 -0400
@@ -3040,7 +3040,7 @@
 # Debian package :                    		"/usr/share/awstats/plugins"
 	my @PossiblePluginsDir = (
 		"$DIR/plugins",
-		"/usr/local/awstats/wwwroot/cgi-bin/plugins",
+		"%%PREFIX%%/www/awstats/cgi-bin/plugins",
 		"/usr/share/awstats/plugins"
 	);
 	my %DirAddedInINC = ();
