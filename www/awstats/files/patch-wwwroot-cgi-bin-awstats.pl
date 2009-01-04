--- wwwroot/cgi-bin/awstats.pl.orig	2008-11-30 10:42:46.000000000 -0500
+++ wwwroot/cgi-bin/awstats.pl	2009-01-03 16:32:27.000000000 -0500
@@ -2925,7 +2925,7 @@
 # Debian package :                    		"/usr/share/awstats/plugins"
 	my @PossiblePluginsDir = (
 							   "$DIR/plugins",
-							   "/usr/local/awstats/wwwroot/cgi-bin/plugins",
+							   "%%PREFIX%%/www/awstats/cgi-bin/plugins",
 							   "/usr/share/awstats/plugins"
 	);
 	my %DirAddedInINC = ();
