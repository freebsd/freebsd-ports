--- html/install.php.orig	2018-08-04 20:07:12 UTC
+++ html/install.php
@@ -357,7 +357,7 @@ $config_file = <<<"EOD"
 
 // This is the user LibreNMS will run as
 //Please ensure this user is created and has the correct permissions to your install
-\$config['user'] = 'librenms';
+\$config['user'] = 'www';
 
 ### Locations - it is recommended to keep the default
 #\$config\['install_dir'\]  = "$install_dir";
@@ -383,8 +383,8 @@ $config_file = <<<"EOD"
 #\$config\['nets'\]\[\] = "192.168.0.0/16";
 
 # Update configuration
-#\$config\['update_channel'\] = 'release';  # uncomment to follow the monthly release channel
-#\$config\['update'\] = 0;  # uncomment to completely disable updates
+\$config\['update_channel'\] = 'release';  # uncomment to follow the monthly release channel
+\$config\['update'\] = 0;  # uncomment to completely disable updates
 EOD;
 
 if (!file_exists("../config.php")) {
