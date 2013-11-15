--- ./src/util.c.orig	2013-11-15 09:53:06.149558492 -0600
+++ ./src/util.c	2013-11-15 09:53:18.903559033 -0600
@@ -123,7 +123,7 @@
         if (tmp) {
             next->path = strdup(tmp);
             /* the root filehandle in hex */
-            if (tmp = strtok(NULL, ":")) {
+            if ((tmp = strtok(NULL, ":"))) {
                 /* hex takes two characters for each byte */
                 fsroot_len = strlen(tmp) / 2;
 
