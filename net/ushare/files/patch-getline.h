--- src/getline.h.orig	Sat Dec 23 02:49:13 2006
+++ src/getline.h	Sat Dec 23 13:24:11 2006
@@ -0,0 +1,8 @@
+#ifndef _GETLINE_H_
+#define _GETLINE_H_
+
+#if defined(__FreeBSD__) || defined(__OpenBSD__)
+ssize_t getline(char **lineptr, size_t *n, FILE *stream);
+#endif
+
+#endif /* _GETLINE_H_ */
