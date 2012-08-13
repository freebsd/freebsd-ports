--- program/include/iniset.php.orig	2012-08-06 18:18:13.000000000 +0200
+++ program/include/iniset.php	2012-08-13 12:37:50.000000000 +0200
@@ -29,7 +29,6 @@
     // critical PHP settings here. Only these, which doesn't provide
     // an error/warning in the logs later. See (#1486307).
     'mbstring.func_overload'  => 0,
-    'suhosin.session.encrypt' => 0,
     'session.auto_start'      => 0,
     'file_uploads'            => 1,
     'magic_quotes_runtime'    => 0,
