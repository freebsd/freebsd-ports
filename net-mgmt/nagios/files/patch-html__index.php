--- ./html/index.php.orig	2013-08-30 19:46:14.000000000 +0200
+++ ./html/index.php	2014-01-14 13:57:06.000000000 +0100
@@ -8,8 +8,9 @@
 </head>
 
 <?php
+include_once(dirname(__FILE__).'/includes/utils.inc.php');
  // allow specifying main window URL for permalinks, etc.
-$corewindow="main.php";
+$corewindow=$cfg["cgi_base_url"]."/tac.cgi";
 if(isset($_GET['corewindow'])){
 	
 	// default window url may have been overridden with a permalink...
