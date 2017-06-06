--- include/global_settings.php.orig	2016-02-07 19:26:54 UTC
+++ include/global_settings.php
@@ -96,7 +96,7 @@ $settings = array(
 			),
 		"path_cactilog" => array(
 			"friendly_name" => "Cacti Log File Path",
-			"description" => "The path to your Cacti log file (if blank, defaults to <path_cacti>/log/cacti.log)",
+			"description" => "The path to your Cacti log file (if blank, defaults to /var/log/cacti/log)",
 			"method" => "filepath",
 			"default" => $config["base_path"] . "/log/cacti.log",
 			"max_length" => "255"
