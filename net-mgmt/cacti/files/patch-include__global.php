--- include/global.php.orig	2017-02-04 14:12:12.747287000 +0000
+++ include/global.php	2017-02-04 14:12:32.931726000 +0000
@@ -126,7 +126,7 @@
 	$config['library_path'] = preg_replace("/(.*[\/])include/", "\\1lib", dirname(__FILE__));
 }
 $config['include_path'] = dirname(__FILE__);
-$config['rra_path'] = $config['base_path'] . '/rra';
+$config['rra_path'] = '/var/db/cacti/rra';
 
 /* for multiple pollers, we need to know this location */
 if (!isset($scripts_path)) {
