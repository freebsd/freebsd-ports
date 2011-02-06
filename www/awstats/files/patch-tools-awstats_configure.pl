--- tools/awstats_configure.pl.old	2010-12-25 19:25:49.000000000 -0600
+++ tools/awstats_configure.pl	2010-12-25 19:33:43.000000000 -0600
@@ -28,12 +28,13 @@
 $AWSTATS_MODEL_CONFIG
 $AWSTATS_DIRDATA_PATH
 /;
-$AWSTATS_PATH='';
-$AWSTATS_ICON_PATH='/usr/local/awstats/wwwroot/icon';
-$AWSTATS_CSS_PATH='/usr/local/awstats/wwwroot/css';
-$AWSTATS_CLASSES_PATH='/usr/local/awstats/wwwroot/classes';
-$AWSTATS_CGI_PATH='/usr/local/awstats/wwwroot/cgi-bin';
-$AWSTATS_MODEL_CONFIG='/etc/awstats/awstats.model.conf';		# Used only when configure ran on linux
+$AWSTATS_PATH='%%PREFIX%%/www/awstats';
+$AWSTATS_ICON_PATH='%%PREFIX%%/www/awstats/icon';
+$AWSTATS_CSS_PATH='%%PREFIX%%/www/awstats/css';
+$AWSTATS_CLASSES_PATH='%%PREFIX%%/www/awstats/classes';
+$AWSTATS_CGI_PATH='%%PREFIX%%/www/awstats/cgi-bin';
+$AWSTATS_MODEL_CONFIG='%%PREFIX%%/etc/awstats/awstats.model.conf';		
+# Used only when configure ran on linux
 $AWSTATS_DIRDATA_PATH='/var/lib/awstats';						# Used only when configure ran on linux
 
 
@@ -64,6 +65,7 @@
 '/etc/httpd/httpd.conf',
 '/usr/local/apache/conf/httpd.conf',
 '/usr/local/apache2/conf/httpd.conf',
+'/usr/local/etc/apache(13/22)/httpd.conf',
 );
 
 use vars qw/
@@ -309,7 +311,8 @@
 	$AWSTATS_PATH=`pwd`; $AWSTATS_PATH =~ s/[\r\n]//;
 	$AWSTATS_PATH=~s/tools[\\\/]?$//;
 	$AWSTATS_PATH=~s/[\\\/]$//;
-	if ($AWSTATS_PATH ne '/usr/local/awstats') {
+#freebsd default %%PREFIX%%/www/awstats
+	if ($AWSTATS_PATH ne '/usr/local/www/awstats') {
 		print "Warning: AWStats standard directory on Linux OS is '/usr/local/awstats'.\n";
 		print "If you want to use standard directory, you should first move all content\n";
 		print "of AWStats distribution from current directory:\n";
@@ -324,10 +327,10 @@
 			print "configure.pl aborted.\n";
 			exit 1;
 		}
-		$AWSTATS_ICON_PATH="$AWSTATS_PATH/wwwroot/icon";
-		$AWSTATS_CSS_PATH="$AWSTATS_PATH/wwwroot/css";
-		$AWSTATS_CLASSES_PATH="$AWSTATS_PATH/wwwroot/classes";
-		$AWSTATS_CGI_PATH="$AWSTATS_PATH/wwwroot/cgi-bin";
+		$AWSTATS_ICON_PATH="$AWSTATS_PATH/icon";
+		$AWSTATS_CSS_PATH="$AWSTATS_PATH/css";
+		$AWSTATS_CLASSES_PATH="$AWSTATS_PATH/classes";
+		$AWSTATS_CGI_PATH="$AWSTATS_PATH/cgi-bin";
 	}
 }
 elsif ($OS eq 'macosx') {
@@ -420,6 +423,7 @@
 
 		print "\n".($bidon?"Now, enter":"Enter")." full config file path of your Web server.\n";
 		print "Example: /etc/httpd/httpd.conf\n";
+		print "Example: %%PREFIX%%/etc/apache(13/22)/httpd.conf";
 		print "Example: /usr/local/apache2/conf/httpd.conf\n";
 		print "Example: c:\\Program files\\apache group\\apache\\conf\\httpd.conf\n";
 		$bidon='';
@@ -527,7 +531,7 @@
 #
 # This is to permit URL access to scripts/files in AWStats directory.
 #
-<Directory "$AWSTATS_PATH/wwwroot">
+<Directory "$AWSTATS_PATH/">
     Options None
     AllowOverride None
     Order allow,deny
@@ -546,12 +550,12 @@
 # -----------------------------
 my $modelfile='';
 if ($OS eq 'linux') 		{ 
-	if (-f "$AWSTATS_PATH/wwwroot/cgi-bin/awstats.model.conf") {
-		$modelfile="$AWSTATS_PATH/wwwroot/cgi-bin/awstats.model.conf";
+	if (-f "$AWSTATS_PATH/cgi-bin/awstats.model.conf") {
+		$modelfile="$AWSTATS_PATH/cgi-bin/awstats.model.conf";
 	}
 	else {
 		$modelfile="$AWSTATS_MODEL_CONFIG";
-		if (! -s $modelfile || ! -w $modelfile) { $modelfile="$AWSTATS_PATH/wwwroot/cgi-bin/awstats.model.conf"; }
+		if (! -s $modelfile || ! -w $modelfile) { $modelfile="$AWSTATS_PATH/cgi-bin/awstats.model.conf"; }
 	}
 }
 elsif ($OS eq "macosx") 		{ 
