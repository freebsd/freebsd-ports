--- ./src/io.c.orig	2012-01-30 12:34:26.000000000 -0800
+++ ./src/io.c	2012-01-30 12:34:36.000000000 -0800
@@ -47,7 +47,7 @@
 extern char* gz_data(char *data)
 {
     char *fn = strdup("/tmp/fbsdmon.XXXXXX");
-    mktemp(fn);
+    mkstemp(fn);
 
     gzFile *gz = gzopen(fn, "wb");
     gzputs(gz, data);
