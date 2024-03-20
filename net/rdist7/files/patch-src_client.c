--- src/client.c.orig	2001-10-22 13:29:21.000000000 -0700
+++ src/client.c	2024-03-19 17:05:24.956590000 -0700
@@ -1009,7 +1009,7 @@
 	/*
 	 * Parse size
 	 */
-	size = (off_t) strtol((const char *)cp, (char **)&cp, 10);
+	size = (off_t) strtoll((const char *)cp, (char **)&cp, 10);
 	if (*cp++ != ' ') {
 		error("update: size not delimited");
 		return(US_NOTHING);
@@ -1018,7 +1018,7 @@
 	/*
 	 * Parse mtime
 	 */
-	mtime = strtol((const char *)cp, (char **)&cp, 10);
+	mtime = strtoll((const char *)cp, (char **)&cp, 10);
 	if (*cp++ != ' ') {
 		error("update: mtime not delimited");
 		return(US_NOTHING);
