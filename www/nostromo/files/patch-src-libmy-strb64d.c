--- src/libmy/strb64d.c.orig	2005-06-04 10:30:04.000000000 +0200
+++ src/libmy/strb64d.c	2013-08-23 19:17:25.700331962 +0200
@@ -54,7 +54,7 @@
 	dst[0] = '\0';
 
 	while (1) {
-		for (i = 0, j = j; i < 4; i++, j++) {
+		for (i = 0; i < 4; i++, j++) {
 			if (src[j] == '\0')
 				goto quit;
 			ch = src[j];
