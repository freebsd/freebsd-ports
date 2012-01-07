Index: lib/charset.c
diff -u -p lib/charset.c.orig lib/charset.c
--- lib/charset.c.orig	2011-10-05 04:59:14.000000000 +0900
+++ lib/charset.c	2012-01-08 03:18:45.000000000 +0900
@@ -861,7 +861,7 @@ void mimeheader_cat(struct convert_rock 
     int len;
     char *res;
 
-    if (!s) return 0;
+    if (!s) return;
 
     /* set up the conversion path */
     input = table_init(0, target);
