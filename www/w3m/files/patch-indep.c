--- indep.c.orig	Mon Oct 29 09:52:32 2001
+++ indep.c	Mon Oct 29 09:52:37 2001
@@ -181,7 +181,7 @@
 
 /* string search using the simplest algorithm */
 char *
-strcasestr(char *s1, char *s2)
+strcasestr(const char *s1, const char *s2)
 {
     int len1, len2;
     len1 = strlen(s1);
