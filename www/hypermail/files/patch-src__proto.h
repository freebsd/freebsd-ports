--- src/proto.h.orig	Thu Jul  3 18:00:18 2003
+++ src/proto.h	Thu Jan  8 00:27:25 2004
@@ -94,7 +94,7 @@
 char *PushString(struct Push *, const char *);
 char *PushNString(struct Push *, const char *, int);
 
-char *strcasestr (char *, const char *);
+// char *strcasestr (char *, const char *);
 char *strsav(const char *);
 char *strreplace(char *, char *);
 void strcpymax(char *, const char *, int);
