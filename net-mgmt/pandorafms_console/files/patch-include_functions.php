--- include/functions.php.orig	2016-04-08 09:50:59 UTC
+++ include/functions.php
@@ -2322,7 +2322,7 @@ function clear_pandora_error_for_header(
 	global $config;
 	
 	$config["alert_cnt"] = 0;
-	$_SESSION["alert_msg"] = "";
+	$_SESSION["alert_msg"] = array();
 }
 
 function set_pandora_error_for_header($message, $title = null) {
