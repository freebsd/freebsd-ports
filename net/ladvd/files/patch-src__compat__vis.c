--- ./src/compat/vis.c.orig	2011-12-20 05:11:03.000000000 -0800
+++ ./src/compat/vis.c	2013-10-20 23:20:15.000000000 -0700
@@ -161,7 +161,7 @@
 }
 
 int
-strnvis(char *dst, const char *src, size_t siz, int flag)
+strnvis(char *dst, size_t siz, const char *src, int flag)
 {
 	char *start, *end;
 	char tbuf[5];
