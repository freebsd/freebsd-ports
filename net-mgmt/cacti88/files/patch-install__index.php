--- install/index.php.orig	2016-03-06 23:26:59 UTC
+++ install/index.php
@@ -63,7 +63,7 @@ if ($old_cacti_version == $config["cacti
 }
 
 function verify_php_extensions() {
-	$extensions = array("session", "sockets", "mysql", "xml");
+	$extensions = array("session", "sockets", "mysqli", "xml");
 	$ok = true;
 	$missing_extension = "	<p style='font-family: Verdana, Arial; font-size: 16px; font-weight: bold; color: red;'>Error</p>
 							<p style='font-family: Verdana, Arial; font-size: 12px;'>The following PHP extensions are missing:</p><ul>";
@@ -267,7 +267,7 @@ $input["path_cactilog"]["description"] =
 if (config_value_exists("path_cactilog")) {
 	$input["path_cactilog"]["default"] = read_config_option("path_cactilog");
 } else {
-	$input["path_cactilog"]["default"] = $config["base_path"] . "/log/cacti.log";
+	$input["path_cactilog"]["default"] = "/var/log/cacti/log";
 }
 
 /* SNMP Version */
