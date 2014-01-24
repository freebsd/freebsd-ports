--- ./html/index.php.orig	2013-11-25 14:16:25.000000000 +0000
+++ ./html/index.php	2014-01-24 22:40:43.000000000 +0000
@@ -8,8 +8,9 @@
 </head>
 
 <?php
+include_once(dirname(__FILE__).'/includes/utils.inc.php');
  // allow specifying main window URL for permalinks, etc.
-$corewindow="main.php";
+$corewindow=$cfg["cgi_base_url"]."/tac.cgi";
 if(isset($_GET['corewindow'])){
 	
 	// default window url may have been overridden with a permalink...
