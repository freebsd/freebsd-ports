--- ./include/global.php.orig	2013-08-06 19:31:19.000000000 -0700
+++ ./include/global.php	2014-08-11 18:37:08.000000000 -0700
@@ -113,7 +113,7 @@
 	$config["library_path"] = preg_replace("/(.*[\/])include/", "\\1lib", dirname(__FILE__));
 }
 $config["include_path"] = dirname(__FILE__);
-$config["rra_path"] = $config["base_path"] . '/rra';
+$config["rra_path"] = '/var/db/cacti/rra';
 
 /* colors */
 $colors["dark_outline"] = "454E53";
