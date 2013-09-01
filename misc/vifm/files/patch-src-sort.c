--- src/sort.c.orig	2013-04-02 18:55:08.000000000 +0300
+++ src/sort.c	2013-04-02 18:37:26.000000000 +0300
@@ -46,7 +46,7 @@
 
 static int sort_dir_list(const void *one, const void *two);
 TSTATIC int strnumcmp(const char s[], const char t[]);
-#if defined(_WIN32) || defined(__APPLE__) || defined(__CYGWIN__)
+#if defined(_WIN32) || defined(__APPLE__) || defined(__CYGWIN__) || defined(__FreeBSD__)
 static int vercmp(const char s[], const char t[]);
 #else
 static char * skip_leading_zeros(const char str[]);
@@ -106,7 +106,7 @@
 TSTATIC int
 strnumcmp(const char s[], const char t[])
 {
-#if defined(_WIN32) || defined(__APPLE__) || defined(__CYGWIN__)
+#if defined(_WIN32) || defined(__APPLE__) || defined(__CYGWIN__) || defined(__FreeBSD__)
 	return vercmp(s, t);
 #else
 	const char *new_s = skip_leading_zeros(s);
@@ -115,7 +115,7 @@
 #endif
 }
 
-#if defined(_WIN32) || defined(__APPLE__) || defined(__CYGWIN__)
+#if defined(_WIN32) || defined(__APPLE__) || defined(__CYGWIN__) || defined(__FreeBSD__)
 static int
 vercmp(const char s[], const char t[])
 {
