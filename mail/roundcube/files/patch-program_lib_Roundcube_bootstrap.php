--- program/lib/Roundcube/bootstrap.php.orig	2017-06-26 20:56:48.000000000 +0200
+++ program/lib/Roundcube/bootstrap.php	2017-06-30 10:20:36.888301000 +0200
@@ -35,7 +35,6 @@ $config = array(
 // check these additional ini settings if not called via CLI
 if (php_sapi_name() != 'cli') {
     $config += array(
-        'suhosin.session.encrypt' => false,
         'file_uploads'            => true,
     );
 }
