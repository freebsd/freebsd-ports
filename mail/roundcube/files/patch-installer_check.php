--- installer/check.php.orig	2010-12-13 17:38:24.000000000 +0100
+++ installer/check.php	2010-12-13 17:38:36.000000000 +0100
@@ -37,7 +37,6 @@
     'session.auto_start'            => 0,
     'zend.ze1_compatibility_mode'   => 0,
     'mbstring.func_overload'        => 0,
-    'suhosin.session.encrypt'       => 0,
 );
 
 $optional_checks = array(
