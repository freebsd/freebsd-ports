--- fileinfo.c.orig	Sat Dec 17 09:00:17 2005
+++ fileinfo.c	Sat Dec 17 09:00:39 2005
@@ -103,7 +103,7 @@
 	intern = ecalloc(1, sizeof(struct finfo_object));
 	intern->zo.ce = class_type;
 	intern->zo.properties = NULL;
-#if ZEND_EXTENSION_API_NO > 220050000
+#if ZEND_MODULE_API_NO >= 20050922
 	intern->zo.guards = NULL;
 #else
 	intern->zo.in_get = 0;
