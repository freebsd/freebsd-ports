--- tools/awstats_configure.pl.orig	2016-07-17 17:51:11 UTC
+++ tools/awstats_configure.pl
@@ -27,7 +27,7 @@ $AWSTATS_CGI_PATH
 $AWSTATS_MODEL_CONFIG
 $AWSTATS_DIRDATA_PATH
 /;
-$AWSTATS_PATH='';
+$AWSTATS_PATH='%%WWWDIR%%';
 $AWSTATS_ICON_PATH='/usr/local/awstats/wwwroot/icon';
 $AWSTATS_CSS_PATH='/usr/local/awstats/wwwroot/css';
 $AWSTATS_CLASSES_PATH='/usr/local/awstats/wwwroot/classes';
@@ -63,6 +63,9 @@ use vars qw/
 '/etc/httpd/httpd.conf',
 '/usr/local/apache/conf/httpd.conf',
 '/usr/local/apache2/conf/httpd.conf',
+'%%LOCALBASE%%/etc/apache13/httpd.conf',
+'%%LOCALBASE%%/etc/apache22/httpd.conf',
+'%%LOCALBASE%%/etc/apache24/httpd.conf'
 );
 
 use vars qw/
@@ -308,7 +311,7 @@ if ($OS eq 'linux') {
 	$AWSTATS_PATH=`pwd`; $AWSTATS_PATH =~ s/[\r\n]//;
 	$AWSTATS_PATH=~s/tools[\\\/]?$//;
 	$AWSTATS_PATH=~s/[\\\/]$//;
-	if ($AWSTATS_PATH ne '/usr/local/awstats') {
+	if ($AWSTATS_PATH ne '%%WWWDIR%%') {
 		print "Warning: AWStats standard directory on Linux OS is '/usr/local/awstats'.\n";
 		print "If you want to use standard directory, you should first move all content\n";
 		print "of AWStats distribution from current directory:\n";
@@ -419,6 +422,7 @@ if (! scalar keys %ApacheConfPath) {
 
 		print "\n".($bidon?"Now, enter":"Enter")." full config file path of your Web server.\n";
 		print "Example: /etc/httpd/httpd.conf\n";
+		print "Example: %%LOCALBASE%%/etc/apache24/httpd.conf\n";
 		print "Example: /usr/local/apache2/conf/httpd.conf\n";
 		print "Example: c:\\Program files\\apache group\\apache\\conf\\httpd.conf\n";
 		$bidon='';
