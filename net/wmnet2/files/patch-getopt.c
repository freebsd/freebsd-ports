--- getopt.c.orig	Fri Oct  9 10:59:00 1998
+++ getopt.c	Tue Apr 27 09:57:46 2004
@@ -209,6 +209,8 @@
 
 char *getenv ();
 extern int strncmp(const char *s1, const char *s2, size_t len);
+extern int strcmp(const char *, const char *);
+extern size_t   strlen(const char *);
 
 static char *
 my_index (str, chr)
