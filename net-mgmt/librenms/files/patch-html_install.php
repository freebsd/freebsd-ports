--- html/install.php.orig	2020-04-30 14:13:30 UTC
+++ html/install.php
@@ -418,14 +418,14 @@ if ($stage == 0) {
 
 # Update configuration
 #\$config\['update_channel'\] = 'release';  # uncomment to follow the monthly release channel
-#\$config\['update'\] = 0;  # uncomment to completely disable updates
+\$config\['update'\] = 0;  # uncomment to completely disable updates
 EOD;
 
     if (!file_exists("{$librenms_dir}/config.php")) {
         $conf = fopen("config.php", 'w');
         if ($conf != false) {
             if (fwrite($conf, "<?php\n") === false) {
-                echo("<div class='alert alert-danger'>We couldn't create the config.php file, please create this manually before continuing by copying the below into a config.php in the root directory of your install (typically /opt/librenms/)</div>");
+                echo("<div class='alert alert-danger'>We couldn't create the config.php file, please create this manually before continuing by copying the below into a config.php in the root directory of your install (typically /usr/local/www/librenms/)</div>");
                 echo("<pre>&lt;?php\n".stripslashes($config_file)."</pre>");
             } else {
                 $config_file = stripslashes($config_file);
@@ -433,7 +433,7 @@ EOD;
                 echo("<div class='alert alert-success'>The config file has been created</div>");
             }
         } else {
-            echo("<div class='alert alert-danger'>We couldn't create the config.php file, please create this manually before continuing by copying the below into a config.php in the root directory of your install (typically /opt/librenms/)</div>");
+            echo("<div class='alert alert-danger'>We couldn't create the config.php file, please create this manually before continuing by copying the below into a config.php in the root directory of your install (typically /usr/local/www/librenms/)</div>");
             echo("<pre>&lt;?php\n".stripslashes($config_file)."</pre>");
         }
     }
