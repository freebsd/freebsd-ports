--- tools/awstats_configure.pl.orig	Sat Jan 15 17:42:58 2005
+++ tools/awstats_configure.pl	Thu Sep 22 20:34:07 2005
@@ -29,10 +29,10 @@
 $AWSTATS_DIRDATA_PATH
 /;
 $AWSTATS_PATH='';
-$AWSTATS_ICON_PATH='/usr/local/awstats/wwwroot/icon';
-$AWSTATS_CSS_PATH='/usr/local/awstats/wwwroot/css';
-$AWSTATS_CLASSES_PATH='/usr/local/awstats/wwwroot/classes';
-$AWSTATS_CGI_PATH='/usr/local/awstats/wwwroot/cgi-bin';
+$AWSTATS_ICON_PATH='%%WWWDIR%%/icon';
+$AWSTATS_CSS_PATH='%%WWWDIR%%/css';
+$AWSTATS_CLASSES_PATH='%%WWWDIR%%/classes';
+$AWSTATS_CGI_PATH='%%WWWDIR%%/cgi-bin';
 $AWSTATS_MODEL_CONFIG='/etc/awstats/awstats.model.conf';		# Used only when configure ran on linux
 $AWSTATS_DIRDATA_PATH='/var/lib/awstats';						# Used only when configure ran on linux

