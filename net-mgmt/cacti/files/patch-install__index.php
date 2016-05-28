--- install/index.php.orig	2016-05-28 10:54:08.124059773 +0100
+++ install/index.php	2016-05-28 10:54:34.252057818 +0100
@@ -63,7 +63,7 @@
 }
 
 function verify_php_extensions() {
-	$extensions = array("session", "sockets", "mysql", "xml");
+	$extensions = array("session", "sockets", "mysqli", "xml");
 	$ok = true;
 	$missing_extension = "	<p style='font-family: Verdana, Arial; font-size: 16px; font-weight: bold; color: red;'>Error</p>
 							<p style='font-family: Verdana, Arial; font-size: 12px;'>The following PHP extensions are missing:</p><ul>";
@@ -267,7 +267,7 @@
 if (config_value_exists("path_cactilog")) {
 	$input["path_cactilog"]["default"] = read_config_option("path_cactilog");
 } else {
-	$input["path_cactilog"]["default"] = $config["base_path"] . "/log/cacti.log";
+	$input["path_cactilog"]["default"] = "/var/log/cacti/log";
 }
 
 /* SNMP Version */
