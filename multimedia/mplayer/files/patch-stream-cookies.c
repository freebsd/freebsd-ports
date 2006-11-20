--- stream/cookies.c.orig	Mon Oct 23 00:32:25 2006
+++ stream/cookies.c	Tue Oct 24 21:52:00 2006
@@ -21,6 +21,10 @@
 
 #define MAX_COOKIES 20
 
+#ifndef SIZE_MAX
+#define SIZE_MAX ((size_t)-1)
+#endif
+
 char *cookies_file = NULL;
 
 typedef struct cookie_list_type {
