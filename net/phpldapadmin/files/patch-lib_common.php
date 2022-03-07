--- lib/common.php.orig	2021-12-12 02:35:51 UTC
+++ lib/common.php
@@ -296,7 +296,9 @@ if ($app['language'] == 'auto') {
  * Strip slashes from GET, POST, and COOKIE variables if this
  * PHP install is configured to automatically addslashes()
  */
-if (@get_magic_quotes_gpc() && (! isset($slashes_stripped) || ! $slashes_stripped)) {
+if (@version_compare(phpversion(), '5.4.0', '<') &&
+    @get_magic_quotes_gpc() &&
+    (!isset($slashes_stripped) || !$slashes_stripped)) {
 	array_stripslashes($_REQUEST);
 	array_stripslashes($_GET);
 	array_stripslashes($_POST);
