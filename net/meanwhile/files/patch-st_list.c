--- src/st_list.c.orig	Mon Jun 28 16:56:44 2004
+++ src/st_list.c	Mon Jun 28 16:56:56 2004
@@ -387,6 +387,7 @@
   b = tmp;
 
   name = b + 4; /* advance past the "1:: " */
+  str_replace(name, ';', ' ');
   tmp = strchr(name, ',');
   if(tmp) {
     *tmp = '\0';
