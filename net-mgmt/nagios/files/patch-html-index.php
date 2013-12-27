--- html/index.php.orig	2013-08-30 21:46:14.000000000 +0400
+++ html/index.php	2013-12-27 11:53:31.000000000 +0400
@@ -43,7 +43,7 @@
 
 <frameset cols="180,*" style="border: 0px; framespacing: 0px">
 <frame src="side.php" name="side" frameborder="0" style="">
-<frame src="<?php echo $corewindow;?>" name="main" frameborder="0" style="">
+<frame src="cgi-bin/tac.cgi" name="main" frameborder="0">
 
 <noframes>
 <!-- This page requires a web browser which supports frames. --> 
