--- Library/Implementation/HTString.c.orig	Tue Jan 29 18:10:31 2002
+++ Library/Implementation/HTString.c	Tue Jan 29 18:11:09 2002
@@ -65,6 +65,7 @@
 /*
 ** strcasestr(s1,s2) -- like strstr(s1,s2) but case-insensitive.
 */
+#ifndef __FreeBSD__
 PUBLIC char * strcasestr (char * s1, char * s2)
 {
     char * ptr = s1;
@@ -85,7 +86,7 @@
     }
     return NULL;
 }
-
+#endif
 
 
 /*	Allocate a new copy of a string, and returns it
