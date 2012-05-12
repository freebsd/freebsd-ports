--- ./scanelf.c.orig	2012-05-12 19:03:38.000000000 +0200
+++ ./scanelf.c	2012-05-12 19:04:14.000000000 +0200
@@ -14,6 +14,10 @@
 
 #define IS_MODIFIER(c) (c == '%' || c == '#' || c == '+')
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC       0x00100000
+#endif
+
 /* prototypes */
 static int file_matches_list(const char *filename, char **matchlist);
 
