--- program/include/iniset.php.orig	2010-04-26 15:54:45.000000000 +0200
+++ program/include/iniset.php	2010-04-26 15:54:53.000000000 +0200
@@ -25,7 +25,6 @@
 // an error/warning in the logs later. See (#1486307).
 $crit_opts = array(
     'mbstring.func_overload' => 0,
-    'suhosin.session.encrypt' => 0,
     'session.auto_start' => 0,
     'file_uploads' => 1,
 );
