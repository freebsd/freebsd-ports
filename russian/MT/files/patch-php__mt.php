--- php/mt.php.orig	2013-12-02 02:40:30.000000000 +0900
+++ php/mt.php	2014-04-16 15:21:49.000000000 +0900
@@ -11,16 +11,16 @@
 require_once('lib/class.exception.php');
 
 define('VERSION', '5.2');
-define('PRODUCT_VERSION', '5.2.9');
+define('PRODUCT_VERSION', '5.2.10');
 
 $PRODUCT_NAME = 'Movable Type';
 if($PRODUCT_NAME == '__PRODUCT' . '_NAME__')
     $PRODUCT_NAME = 'Movable Type';
 define('PRODUCT_NAME', $PRODUCT_NAME);
 
-$RELEASE_NUMBER = '9';
+$RELEASE_NUMBER = '10';
 if ( $RELEASE_NUMBER == '__RELEASE_' . 'NUMBER__' )
-    $RELEASE_NUMBER = 9;
+    $RELEASE_NUMBER = 10;
 define('RELEASE_NUMBER', $RELEASE_NUMBER);
 
 $PRODUCT_VERSION_ID = '5.2.9-ru';
