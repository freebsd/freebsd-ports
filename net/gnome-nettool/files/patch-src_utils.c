--- src/utils.c.orig	Sun Jul  4 20:11:49 2004
+++ src/utils.c	Sun Jul  4 20:12:14 2004
@@ -240,7 +240,7 @@
 	const gchar *unit = "B";
 	gchar *result;
 	
-	sscanf (bytes, "%lld", &rx);
+	rx = strtoull (bytes, (char **)NULL, 10);
 	short_rx = rx * 10;  
 
 	if (rx > 1125899906842624ull) {
