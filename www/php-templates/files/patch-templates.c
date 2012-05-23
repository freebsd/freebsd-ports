--- templates.c.orig	2012-05-23 09:56:51.000000000 +0200
+++ templates.c	2012-05-23 09:57:08.000000000 +0200
@@ -48,7 +48,7 @@
 int		le_templates;
 
 /* {{{ templates_functions[] */
-function_entry templates_functions[] = {
+zend_function_entry templates_functions[] = {
 	PHP_FE(tmpl_open,		NULL)
 	PHP_FE(tmpl_load,		NULL)
 	PHP_FE(tmpl_close,		NULL)
