--- php_screw.c.orig	2010-04-11 10:55:39.000000000 +0200
+++ php_screw.c	2010-04-11 10:56:01.000000000 +0200
@@ -121,7 +121,6 @@
 
 PHP_MINIT_FUNCTION(php_screw)
 {
-	CG(extended_info) = 1;
 
 	org_compile_file = zend_compile_file;
 	zend_compile_file = pm9screw_compile_file;
@@ -130,7 +129,6 @@
 
 PHP_MSHUTDOWN_FUNCTION(php_screw)
 {
-	CG(extended_info) = 1;
 	zend_compile_file = org_compile_file;
 	return SUCCESS;
 }
