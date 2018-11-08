--- html/install.php.orig	2018-10-17 10:33:28 UTC
+++ html/install.php
@@ -358,7 +358,7 @@ $config_file = <<<"EOD"
 
 // This is the user LibreNMS will run as
 //Please ensure this user is created and has the correct permissions to your install
-\$config['user'] = 'librenms';
+\$config['user'] = 'www';
 
 ### Locations - it is recommended to keep the default
 #\$config\['install_dir'\]  = "$install_dir";
@@ -384,15 +384,15 @@ $config_file = <<<"EOD"
 #\$config\['nets'\]\[\] = "192.168.0.0/16";
 
 # Update configuration
-#\$config\['update_channel'\] = 'release';  # uncomment to follow the monthly release channel
-#\$config\['update'\] = 0;  # uncomment to completely disable updates
+\$config\['update_channel'\] = 'release';  # uncomment to follow the monthly release channel
+\$config\['update'\] = 0;  # uncomment to completely disable updates
 EOD;
 
 if (!file_exists("../config.php")) {
     $conf = fopen("../config.php", 'w');
     if ($conf != false) {
         if (fwrite($conf, "<?php\n") === false) {
-            echo("<div class='alert alert-danger'>We couldn't create the config.php file, please create this manually before continuing by copying the below into a config.php in the root directory of your install (typically /opt/librenms/)</div>");
+            echo("<div class='alert alert-danger'>We couldn't create the config.php file, please create this manually before continuing by copying the below into a config.php in the root directory of your install (typically /usr/local/www/librenms/)</div>");
             echo("<pre>&lt;?php\n".stripslashes($config_file)."</pre>");
         } else {
             $config_file = stripslashes($config_file);
@@ -400,7 +400,7 @@ if (!file_exists("../config.php")) {
             echo("<div class='alert alert-success'>The config file has been created</div>");
         }
     } else {
-        echo("<div class='alert alert-danger'>We couldn't create the config.php file, please create this manually before continuing by copying the below into a config.php in the root directory of your install (typically /opt/librenms/)</div>");
+        echo("<div class='alert alert-danger'>We couldn't create the config.php file, please create this manually before continuing by copying the below into a config.php in the root directory of your install (typically /usr/local/www/librenms/)</div>");
         echo("<pre>&lt;?php\n".stripslashes($config_file)."</pre>");
     }
 }
