--- wwwroot/cgi-bin/awstats.pl.orig	Thu Feb 24 16:02:23 2005
+++ wwwroot/cgi-bin/awstats.pl	Thu Sep 22 20:33:18 2005
@@ -1835,7 +1835,7 @@
 	# Windows and standard package:        		"$DIR/plugins" (plugins in same dir than awstats.pl)
 	# Redhat :                                  "/usr/local/awstats/wwwroot/cgi-bin/plugins"
 	# Debian package :                    		"/usr/share/awstats/plugins"
-	my @PossiblePluginsDir=("$DIR/plugins","/usr/local/awstats/wwwroot/cgi-bin/plugins","/usr/share/awstats/plugins");
+	my @PossiblePluginsDir=("$DIR/plugins","%%PREFIX%%/www/awstats/cgi-bin/plugins","/usr/share/awstats/plugins");
  	my %DirAddedInINC=();

 	#Removed for security reason
