--- util.c.orig	2002-05-13 16:27:29 UTC
+++ util.c
@@ -180,7 +180,7 @@ rename_uniq(const char *from, char **to)
 
 
 char *
-getline(FILE *f)
+get_line(FILE *f)
 {
     static char *b;
     static int bsize;
@@ -234,7 +234,7 @@ getline(FILE *f)
 void
 skip_rest(FILE *f)
 {
-    while (getline(f) != NULL)
+    while (get_line(f) != NULL)
 	;
 }
 
