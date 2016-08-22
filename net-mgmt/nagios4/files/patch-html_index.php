--- html/index.php.orig	2016-08-01 15:46:23 UTC
+++ html/index.php
@@ -1,6 +1,7 @@
 <?php
+include_once(dirname(__FILE__).'/includes/utils.inc.php');
 // Allow specifying main window URL for permalinks, etc.
-$url = 'main.php';
+$url = $cfg['cgi_base_url'].'/tac.cgi';
 
 if (isset($_GET['corewindow'])) {
 
