--- mod_log_mysql.c.orig	Sun Jan 27 20:03:27 2002
+++ mod_log_mysql.c	Sun Jan 27 20:03:47 2002
@@ -856,7 +856,7 @@
 
 
 /* The configuration array that sets up the hooks into the module. */
-module mysql_log_module = {
+module log_mysql_module = {
 	STANDARD_MODULE_STUFF,
 	NULL,					 /* initializer */
 	NULL,					 /* create per-dir config */
