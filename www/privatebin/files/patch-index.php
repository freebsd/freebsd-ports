--- index.php.orig	2017-10-08 10:27:37 UTC
+++ index.php
@@ -12,6 +12,7 @@
 
 // change this, if your php files and data is outside of your webservers document root
 define('PATH', '');
+define('DATADBDIR', '%%DATADBDIR%%');
 
 define('PUBLIC_PATH', __DIR__);
 require PATH . 'vendor' . DIRECTORY_SEPARATOR . 'autoload.php';
