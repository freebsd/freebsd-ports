--- html/index.php.orig	2014-08-12 15:00:01 UTC
+++ html/index.php
@@ -1,6 +1,7 @@
 <?php
+include_once(dirname(__FILE__).'/includes/utils.inc.php');
 // Allow specifying main window URL for permalinks, etc.
-$url = 'main.php';
+$url = $cfg['cgi_base_url'].'/tac.cgi';
 if (isset($_GET['corewindow'])) {
 
 	// The default window url may have been overridden with a permalink...
