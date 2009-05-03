--- src/conf_cookie.c.orig	2009-05-03 12:39:27.000000000 +0300
+++ src/conf_cookie.c	2009-05-03 12:39:48.000000000 +0300
@@ -23,11 +23,3 @@
 	}
 	return i;
 }
-
-cookie_io_functions_t conf_cookie = {
-	.read = &conf_read,
-	.write = NULL,
-	.seek = NULL,
-	.close = NULL,
-};
-
