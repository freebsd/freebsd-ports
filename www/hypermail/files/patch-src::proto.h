--- src/proto.h.orig	Mon Dec 24 12:40:11 2001
+++ src/proto.h	Mon Dec 24 12:40:19 2001
@@ -88,7 +88,7 @@
 char *strsav(const char *);
 char *strreplace(char *, char *);
 void strcpymax(char *, const char *, int);
-char *strcasestr(char *, const char *);
+/* char *strcasestr(char *, const char *); */
 char *stripzone(char *);
 int numstrchr(char *, char);
 char *getvalue(char *);
