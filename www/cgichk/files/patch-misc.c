--- misc.c.orig	2007-11-08 13:41:34.000000000 +0000
+++ misc.c	2007-11-08 13:43:22.000000000 +0000
@@ -92,7 +92,7 @@
 		hasport = 1;
 	
 	if (t = (char *)index(u, '/'))						// does host have path?
-		(char *)haspath = 1;
+		haspath = 1;
 
 	if (hasport)
 		t = (char *)index(u, ':');
@@ -209,7 +209,7 @@
 	return str;
 }
 /*----------------------------------------------------------------*/
-char *strnstr(const char *HAYSTACK, const char *NEEDLE)
+char *cgichk_strnstr(const char *HAYSTACK, const char *NEEDLE)
 {
   char	*h, *n, *res;
 
