--- html/install.php.orig	2019-05-12 00:03:11 UTC
+++ html/install.php
@@ -362,7 +362,7 @@ $config_file = <<<"EOD"
 
 // This is the user LibreNMS will run as
 //Please ensure this user is created and has the correct permissions to your install
-\$config['user'] = 'librenms';
+\$config['user'] = 'www';
 
 ### Locations - it is recommended to keep the default
 #\$config\['install_dir'\]  = "$install_dir";
@@ -389,14 +389,14 @@ $config_file = <<<"EOD"
 
 # Update configuration
 #\$config\['update_channel'\] = 'release';  # uncomment to follow the monthly release channel
-#\$config\['update'\] = 0;  # uncomment to completely disable updates
+\$config\['update'\] = 0;  # uncomment to completely disable updates
 EOD;
 
 if (!file_exists("config.php")) {
     $conf = fopen("config.php", 'w');
     if ($conf != false) {
         if (fwrite($conf, "<?php\n") === false) {
-            echo("<div class='alert alert-danger'>We couldn't create the config.php file, please create this manually before continuing by copying the below into a config.php in the root directory of your install (typically /opt/librenms/)</div>");
+            echo("<div class='alert alert-danger'>We couldn't create the config.php file, please create this manually before continuing by copying the below into a config.php in the root directory of your install (typically /usr/local/www/librenms/)</div>");
             echo("<pre>&lt;?php\n".stripslashes($config_file)."</pre>");
         } else {
             $config_file = stripslashes($config_file);
@@ -404,7 +404,7 @@ if (!file_exists("config.php")) {
             echo("<div class='alert alert-success'>The config file has been created</div>");
         }
     } else {
-        echo("<div class='alert alert-danger'>We couldn't create the config.php file, please create this manually before continuing by copying the below into a config.php in the root directory of your install (typically /opt/librenms/)</div>");
+        echo("<div class='alert alert-danger'>We couldn't create the config.php file, please create this manually before continuing by copying the below into a config.php in the root directory of your install (typically /usr/local/www/librenms/)</div>");
         echo("<pre>&lt;?php\n".stripslashes($config_file)."</pre>");
     }
 }
