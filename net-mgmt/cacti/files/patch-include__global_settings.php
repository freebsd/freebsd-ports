--- ./include/global_settings.php.orig	2013-08-06 19:31:19.000000000 -0700
+++ ./include/global_settings.php	2014-08-11 18:37:08.000000000 -0700
@@ -96,9 +96,9 @@
 			),
 		"path_cactilog" => array(
 			"friendly_name" => "Cacti Log File Path",
-			"description" => "The path to your Cacti log file (if blank, defaults to <path_cacti>/log/cacti.log)",
+			"description" => "The path to your Cacti log file (if blank, defaults to /var/log/cacti/log)",
 			"method" => "filepath",
-			"default" => $config["base_path"] . "/log/cacti.log",
+			"default" => "/var/log/cacti/log",
 			"max_length" => "255"
 			),
 		"pollerpaths_header" => array(
