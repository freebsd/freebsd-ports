--- libs/extract.c.orig	Wed Apr 23 00:45:18 2003
+++ libs/extract.c	Wed Apr 23 00:45:58 2003
@@ -54,6 +54,8 @@
 	int temp1_fd, temp2_fd, errors_fd;
 #endif
 
+	setenv("XML_CATALOG_FILES", SK_XML_CATALOGS, 1);
+
 	if (input_file == NULL ||
 	    stylesheets == NULL ||
 	    outputs == NULL) {
