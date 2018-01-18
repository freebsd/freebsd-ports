--- html/install.php.orig	2017-12-31 20:48:36 UTC
+++ html/install.php
@@ -364,7 +364,7 @@ $config_file = <<<"EOD"
 
 // This is the user LibreNMS will run as
 //Please ensure this user is created and has the correct permissions to your install
-\$config['user'] = 'librenms';
+\$config['user'] = 'www';
 
 ### Memcached config - We use this to store realtime usage
 \$config\['memcached'\]\['enable'\]  = FALSE;
@@ -395,7 +395,7 @@ $config_file = <<<"EOD"
 #\$config\['nets'\]\[\] = "192.168.0.0/16";
 
 # Uncomment the next line to disable daily updates
-#\$config\['update'\] = 0;
+\$config\['update'\] = 0;
 EOD;
 
 if (!file_exists("../config.php")) {
