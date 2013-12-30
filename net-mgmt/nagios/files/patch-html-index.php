--- html/index.php.orig	2013-08-30 21:46:14.000000000 +0400
+++ html/index.php	2013-12-27 15:56:06.000000000 +0400
@@ -8,6 +8,7 @@
 </head>
 
 <?php
+include_once(dirname(__FILE__).'/includes/utils.inc.php');
  // allow specifying main window URL for permalinks, etc.
-$corewindow="main.php";
+$corewindow=$cfg["cgi_base_url"]."/tac.cgi";
 if(isset($_GET['corewindow'])){
 	
 	// default window url may have been overridden with a permalink...
