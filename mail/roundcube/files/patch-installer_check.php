--- installer/check.php.orig	2017-06-26 20:56:47.000000000 +0200
+++ installer/check.php	2017-06-30 10:20:01.306208000 +0200
@@ -43,7 +43,6 @@ $ini_checks = array(
     'file_uploads'                  => 1,
     'session.auto_start'            => 0,
     'mbstring.func_overload'        => 0,
-    'suhosin.session.encrypt'       => 0,
 );
 
 $optional_checks = array(
