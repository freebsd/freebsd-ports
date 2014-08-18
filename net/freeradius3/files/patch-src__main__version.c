--- ./src/main/version.c.orig	2014-08-16 16:06:51.000000000 -0400
+++ ./src/main/version.c	2014-08-16 16:07:43.000000000 -0400
@@ -53,7 +53,6 @@
 		       (unsigned long) ssl_built,
 		       (unsigned long) ssl_linked);
 
-		return -1;
 	};
 
 	return 0;
