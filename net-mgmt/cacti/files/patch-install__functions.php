--- install/functions.php.orig	2017-02-04 14:21:02.093580000 +0000
+++ install/functions.php	2017-02-04 14:21:31.615575000 +0000
@@ -365,7 +365,7 @@
 	if (config_value_exists('path_cactilog')) {
 		$input['path_cactilog']['default'] = read_config_option('path_cactilog');
 	} else {
-		$input['path_cactilog']['default'] = $config['base_path'] . '/log/cacti.log';
+		$input['path_cactilog']['default'] = '/var/log/cacti/log';
 	}
 
 	/* Theme */
