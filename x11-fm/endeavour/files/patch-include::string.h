--- include/string.h.orig	Tue Jan 29 16:54:50 2002
+++ include/string.h	Tue Jan 29 16:55:21 2002
@@ -24,7 +24,9 @@
 extern int strcasecmp(const char *s1, const char *s2);
 #endif
 extern const char *strseekblank(const char *s);
+#ifndef __FreeBSD__
 extern const char *strcasestr(const char *haystack, const char *needle);
+#endif
 extern int strpfx(const char *str, const char *pfx);
 extern int strcasepfx(const char *str, const char *pfx);
 extern void strtoupper(char *s);
