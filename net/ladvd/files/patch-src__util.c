--- src/util.c.orig	2011-12-20 14:11:03.000000000 +0100
+++ src/util.c	2015-03-08 22:30:38.673935000 +0100
@@ -213,9 +213,6 @@
     FILE *file;
     int ret = 0;
 
-    if (path == NULL || line == NULL)
-	return(0);
-
     if ((file = fopen(path, "r")) == NULL)
 	return(0);
 
@@ -232,9 +229,6 @@
 int write_line(const char *path, char *line, uint16_t len) {
     int fd, ret;
 
-    if (path == NULL || line == NULL)
-	return(0);
-
     if ((fd = open(path, O_WRONLY|O_TRUNC)) == -1)
 	return(0);
 
