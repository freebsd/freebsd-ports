--- iiimp/iiimpSwitcher.c.orig	Thu Apr 29 23:04:48 2004
+++ iiimp/iiimpSwitcher.c	Wed Oct 13 21:25:32 2004
@@ -108,14 +108,16 @@
 char *
 my_stpcpy (char *dest, const char *src)
 {
+#ifndef HAVE_STPCPY
+  register char *d = dest;
+  register const char *s = src;
+#endif
+
   if (dest == NULL || src == NULL)
     return NULL;
 #ifdef HAVE_STPCPY
   return stpcpy (dest, src);
 #else
-  register char *d = dest;
-  register const char *s = src;
-
   do
     *d++ = *s;
   while (*s++ != '\0');
