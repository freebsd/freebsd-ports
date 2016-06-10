--- program/lib/Roundcube/bootstrap.php.orig	2016-05-22 11:06:47 UTC
+++ program/lib/Roundcube/bootstrap.php
@@ -37,7 +37,6 @@ $config = array(
 // check these additional ini settings if not called via CLI
 if (php_sapi_name() != 'cli') {
     $config += array(
-        'suhosin.session.encrypt' => false,
         'file_uploads'            => true,
     );
 }
