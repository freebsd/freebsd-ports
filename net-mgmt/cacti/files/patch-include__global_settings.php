--- include/global_settings.php.orig	2017-08-13 04:06:37 UTC
+++ include/global_settings.php
@@ -144,9 +144,9 @@ $settings = array(
 			),
 		'path_cactilog' => array(
 			'friendly_name' => __('Cacti Log Path'),
-			'description' => __('The path to your Cacti log file (if blank, defaults to <path_cacti>/log/cacti.log)'),
+			'description' => __('The path to your Cacti log file (if blank, defaults to /var/log/cacti/log)'),
 			'method' => 'filepath',
-			'default' => $config['base_path'] . '/log/cacti.log',
+			'default' => '/var/log/cacti/log',
 			'max_length' => '255'
 			),
 		'logrotate_enabled' => array(
