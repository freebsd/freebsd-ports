--- src/proto.h.orig	2014-09-19 05:03:40.694275686 +0200
+++ src/proto.h	2014-09-19 05:03:48.494270677 +0200
@@ -104,7 +104,7 @@
 char *PushString(struct Push *, const char *);
 char *PushNString(struct Push *, const char *, int);
 
-char *strcasestr (const char *, const char *);
+// char *strcasestr (const char *, const char *);
 char *strsav(const char *);
 char *strreplace(char *, char *);
 void strcpymax(char *, const char *, int);
