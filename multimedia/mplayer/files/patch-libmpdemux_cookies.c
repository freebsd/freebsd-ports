--- libmpdemux/cookies.c.orig	Mon Jun 12 03:35:46 2006
+++ libmpdemux/cookies.c	Tue Aug 15 03:01:58 2006
@@ -20,6 +20,10 @@
 
 #define MAX_COOKIES 20
 
+#ifndef SIZE_MAX
+#define SIZE_MAX ((size_t)-1)
+#endif
+
 char *cookies_file = NULL;
 
 typedef struct cookie_list_type {
