--- html/index.php.orig	2013-08-30 21:46:14.000000000 +0400
+++ html/index.php	2013-12-27 15:56:06.000000000 +0400
@@ -8,6 +8,7 @@
 </head>
 
 <?php
+include_once(dirname(__FILE__).'/includes/utils.inc.php');
  // allow specifying main window URL for permalinks, etc.
 $corewindow="main.php";
 if(isset($_GET['corewindow'])){
@@ -43,7 +44,7 @@
 
 <frameset cols="180,*" style="border: 0px; framespacing: 0px">
 <frame src="side.php" name="side" frameborder="0" style="">
-<frame src="<?php echo $corewindow;?>" name="main" frameborder="0" style="">
+<frame src="<?php echo $cfg["cgi_base_url"];?>/tac.cgi" name="main" frameborder="0">
 
 <noframes>
 <!-- This page requires a web browser which supports frames. --> 
