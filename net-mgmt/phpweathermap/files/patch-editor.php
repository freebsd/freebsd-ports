--- editor.php.orig	2011-01-06 16:39:40.000000000 +0800
+++ editor.php	2011-01-07 21:38:39.000000000 +0800
@@ -1,10 +1,10 @@
 <?php
 	
 require_once 'editor.inc.php';
-require_once 'Weathermap.class.php';
+require_once '%%DATADIR%%/Weathermap.class.php';
 
 // so that you can't have the editor active, and not know about it.
-$ENABLED=false;
+$ENABLED=true;
 
 if(! $ENABLED)
 {
@@ -17,7 +17,7 @@
 $mapdir='configs';
 $cacti_base = '../../';
 $cacti_url = '/';
-$ignore_cacti=FALSE;
+$ignore_cacti=true;
 $configerror = '';
 
 $config_loaded = @include_once 'editor-config.php';
