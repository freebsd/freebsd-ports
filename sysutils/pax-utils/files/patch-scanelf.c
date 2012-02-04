--- ./scanelf.c.orig	2012-02-04 05:19:34.000000000 +0100
+++ ./scanelf.c	2012-02-04 05:19:59.000000000 +0100
@@ -14,6 +14,10 @@
 
 #define IS_MODIFIER(c) (c == '%' || c == '#' || c == '+')
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC       0x00100000
+#endif
+
 /* prototypes */
 static int file_matches_list(const char *filename, char **matchlist);
 
