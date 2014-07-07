--- program/lib/Roundcube/bootstrap.php.orig	2014-07-07 18:18:50.261368902 +0000
+++ program/lib/Roundcube/bootstrap.php	2014-07-07 18:18:58.202127091 +0000
@@ -38,7 +38,6 @@
 // check these additional ini settings if not called via CLI
 if (php_sapi_name() != 'cli') {
     $config += array(
-        'suhosin.session.encrypt' => false,
         'file_uploads'            => true,
     );
 }
