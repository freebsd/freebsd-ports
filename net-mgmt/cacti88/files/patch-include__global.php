--- include/global.php.orig	2016-03-06 23:26:59 UTC
+++ include/global.php
@@ -116,7 +116,7 @@ if ($config["cacti_server_os"] == "win32
 	$config["library_path"] = preg_replace("/(.*[\/])include/", "\\1lib", dirname(__FILE__));
 }
 $config["include_path"] = dirname(__FILE__);
-$config["rra_path"] = $config["base_path"] . '/rra';
+$config["rra_path"] = '/var/db/cacti/rra';
 
 /* colors */
 $colors["dark_outline"] = "454E53";
