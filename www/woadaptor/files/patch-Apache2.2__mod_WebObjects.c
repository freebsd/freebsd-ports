--- ./Apache2.2/mod_WebObjects.c.orig	2006-07-04 03:02:19.000000000 +0000
+++ ./Apache2.2/mod_WebObjects.c	2009-12-24 21:08:30.218922187 +0000
@@ -304,7 +304,7 @@
     apr_table_do(copyTableEntries, (void *)req, proc_env, NULL);
 
 
-#ifdef APACHE_SECURITY_ENABLED
+#ifdef APACHE_SECURITY_ENABLEDXXXX
 	/******client cert support***** */
 		
 	if (req_is_https(r)) {
