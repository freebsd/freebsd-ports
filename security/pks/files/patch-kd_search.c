--- kd_search.c.orig	2003-08-04 19:57:34 UTC
+++ kd_search.c
@@ -1058,7 +1058,7 @@ word_key_intersect (void *e, void *c)
   if (we->len > sizeof (word))
     {
       s->err->fatal = 0;
-      sprintf (s->err->buf, "search word is greater than %d characters",
+      sprintf (s->err->buf, "search word is greater than %zu characters",
 	       sizeof (word));
       return (0);
     }
