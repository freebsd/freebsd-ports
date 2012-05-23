--- radius.c.orig	2012-05-23 09:36:48.000000000 +0200
+++ radius.c	2012-05-23 09:37:04.000000000 +0200
@@ -62,7 +62,7 @@
  *
  * Every user visible function must have an entry in radius_functions[].
  */
-function_entry radius_functions[] = {
+zend_function_entry radius_functions[] = {
 	PHP_FE(radius_auth_open,    NULL)
 	PHP_FE(radius_acct_open,    NULL)
 	PHP_FE(radius_close,        NULL)
