--- html/db.php.orig	Wed Sep 28 01:52:53 2005
+++ html/db.php	Wed Sep 28 01:54:51 2005
@@ -2,7 +2,7 @@
 
 // will need include of config.php
 include_once('config.php');
-include_once('adodb/adodb.inc.php');
+include_once('%%LOCALBASE%%/share/adodb/adodb.inc.php');
 
 function getdb()
 {
