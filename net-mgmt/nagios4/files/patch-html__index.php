--- ./html/index.php.orig	2014-06-03 16:41:42.000000000 +0200
+++ ./html/index.php	2014-06-05 12:49:28.000000000 +0200
@@ -1,6 +1,7 @@
 <?php
+include_once(dirname(__FILE__).'/includes/utils.inc.php');
 // Allow specifying main window URL for permalinks, etc.
-$url = 'main.php';
+$url = $cfg['cgi_base_url'].'/tac.cgi';
 if (isset($_GET['corewindow'])) {
 
 	// The default window url may have been overridden with a permalink...
