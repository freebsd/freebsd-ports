--- ./sqwebmail/showmsg2html.c.orig	2011-04-29 11:57:03.000000000 +0200
+++ ./sqwebmail/showmsg2html.c	2011-04-29 11:57:26.000000000 +0200
@@ -14,6 +14,12 @@
 #include	<string.h>
 #include	<errno.h>
 
+void error(const char *p)
+{
+        fprintf(stderr, "%s\n", p);
+        exit(1);
+}
+
 void rfc2045_error(const char *p)
 {
 	fprintf(stderr, "%s\n", p);
