--- src/parse.c.orig	Sun Jun 12 16:22:42 2005
+++ src/parse.c	Fri Jan  5 17:54:55 2007
@@ -19,7 +19,8 @@
 void parse(option * o, const char *file)
 {
     FILE *f = fopen(file, "r");
-    unsigned int line_number, i;
+    unsigned int line_number;
+    int i;
     char line[BUFSIZ];
     char *arg, *cmt, *opt;
     config *scan;
