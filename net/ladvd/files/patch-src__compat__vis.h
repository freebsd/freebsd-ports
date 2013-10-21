--- ./src/compat/vis.h.orig	2011-12-20 05:11:03.000000000 -0800
+++ ./src/compat/vis.h	2013-10-20 23:20:50.000000000 -0700
@@ -80,7 +80,7 @@
 
 char	*vis(char *, int, int, int);
 int	strvis(char *, const char *, int);
-int	strnvis(char *, const char *, size_t, int);
+int	strnvis(char *, size_t, const char *, int);
 int	strvisx(char *, const char *, size_t, int);
 int	strunvis(char *, const char *);
 int	unvis(char *, char, int *, int);
