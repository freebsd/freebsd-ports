--- include/string.h.orig	Sat Feb 23 16:37:45 2002
+++ include/string.h	Sat Feb 23 16:37:48 2002
@@ -24,7 +24,9 @@
 extern int strcasecmp(const char *s1, const char *s2);
 #endif
 extern const char *strseekblank(const char *s);
+#ifdef NEED_STRCASESTR
 extern const char *strcasestr(const char *haystack, const char *needle);
+#endif
 extern int strpfx(const char *str, const char *pfx);
 extern int strcasepfx(const char *str, const char *pfx);
 extern void strtoupper(char *s);
