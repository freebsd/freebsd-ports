--- ./kd_search.c.orig	2003-08-04 21:57:34.000000000 +0200
+++ ./kd_search.c	2014-08-15 18:37:29.000000000 +0200
@@ -1058,8 +1058,8 @@
   if (we->len > sizeof (word))
     {
       s->err->fatal = 0;
-      sprintf (s->err->buf, "search word is greater than %d characters",
-	       sizeof (word));
+      sprintf (s->err->buf, "search word is greater than %lu characters",
+	       (unsigned long)sizeof (word));
       return (0);
     }
 
