--- src/strndup.h.orig	Sat Dec 23 02:49:13 2006
+++ src/strndup.h	Sat Dec 23 13:24:04 2006
@@ -0,0 +1,8 @@
+#ifndef _STRNDUP_H_
+#define _STRNDUP_H_
+
+#if defined(__FreeBSD__) || defined(__OpenBSD__)
+char *strndup(const char *s, size_t n);
+#endif
+
+#endif /* _STRNDUP_H_ */
