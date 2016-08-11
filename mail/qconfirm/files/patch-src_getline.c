--- src/getline.c.orig	2004-12-12 16:57:17 UTC
+++ src/getline.c
@@ -2,7 +2,7 @@
 #include "stralloc.h"
 #include "byte.h"
 
-int getline(buffer *b, stralloc *line) {
+int get_line(buffer *b, stralloc *line) {
   int r, i;
   char *x;
 
