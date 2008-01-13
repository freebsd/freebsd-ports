--- wwwroot/cgi-bin/awstats.pl.orig	Sun Jan 15 22:28:43 2006
+++ wwwroot/cgi-bin/awstats.pl	Sun Jan 15 22:30:17 2006
@@ -1911,7 +1911,7 @@
 	# Windows and standard package:        		"$DIR/plugins" (plugins in same dir than awstats.pl)
 	# Redhat :                                  "/usr/local/awstats/wwwroot/cgi-bin/plugins"
 	# Debian package :                    		"/usr/share/awstats/plugins"
-	my @PossiblePluginsDir=("$DIR/plugins","/usr/local/awstats/wwwroot/cgi-bin/plugins","/usr/share/awstats/plugins");
+	my @PossiblePluginsDir=("$DIR/plugins","%%WWWDIR%%/cgi-bin/plugins","/usr/share/awstats/plugins");
  	my %DirAddedInINC=();
 
 	#Removed for security reason
