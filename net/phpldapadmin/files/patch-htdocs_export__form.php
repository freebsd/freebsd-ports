--- htdocs/export_form.php.orig	2021-12-12 02:35:51 UTC
+++ htdocs/export_form.php
@@ -166,7 +166,7 @@ function get_line_end_format() {
  */
 function get_user_agent_string() {
 	if (isset($_SERVER['HTTP_USER_AGENT']))
-		return strtolower($_SERVER['HTTP_USER_AGENT']);
+		return strtolower((string) $_SERVER['HTTP_USER_AGENT']);
 	else
 		return '';
 }
