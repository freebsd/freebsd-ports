--- include/global.php.bak	2015-03-12 03:07:05.768314249 -0700
+++ include/global.php	2015-03-12 03:08:04.171320391 -0700
@@ -113,7 +113,7 @@
 	$config["library_path"] = preg_replace("/(.*[\/])include/", "\\1lib", dirname(__FILE__));
 }
 $config["include_path"] = dirname(__FILE__);
-$config["rra_path"] = $config["base_path"] . '/rra';
+$config["rra_path"] = '/var/db/cacti/rra';
 
 /* colors */
 $colors["dark_outline"] = "454E53";
