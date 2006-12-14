--- src/ushare.h.orig	Sun Nov 12 13:40:36 2006
+++ src/ushare.h	Wed Dec 13 17:16:10 2006
@@ -101,4 +101,14 @@
 
 inline void display_headers (void);
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#ifndef HAVE_STRNDUP
+char *strndup(const char *s, size_t n);
+#endif
+
+#ifndef HAVE_GETLINE
+ssize_t getline(char **lineptr, size_t *n, FILE *stream);
+#endif
+#endif
+
 #endif /* _USHARE_H_ */
