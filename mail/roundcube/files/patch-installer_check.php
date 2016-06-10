--- installer/check.php.orig	2016-05-22 11:06:45 UTC
+++ installer/check.php
@@ -43,7 +43,6 @@ $ini_checks = array(
     'file_uploads'                  => 1,
     'session.auto_start'            => 0,
     'mbstring.func_overload'        => 0,
-    'suhosin.session.encrypt'       => 0,
     'magic_quotes_runtime'          => 0,
     'magic_quotes_sybase'           => 0,
 );
