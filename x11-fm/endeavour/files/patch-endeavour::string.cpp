--- endeavour/string.cpp.orig	Sat Feb 23 16:24:43 2002
+++ endeavour/string.cpp	Sat Feb 23 16:27:03 2002
@@ -35,7 +35,9 @@
 #endif	/* __MSW__ */
 
 const char *strseekblank(const char *s);
+#ifdef NEED_STRCASESTR
 const char *strcasestr(const char *haystack, const char *needle);
+#endif
 int strpfx(const char *str, const char *pfx);
 int strcasepfx(const char *str, const char *pfx);
 void strtoupper(char *s);
@@ -219,6 +221,7 @@
  *	Case insensitive version of strstr(). Returns the pointer to
  *	needle in haystack if found or NULL on no match.
  */
+#ifdef NEED_STRCASESTR
 const char *strcasestr(const char *haystack, const char *needle)
 {
 	const char *strptr1, *strptr2, *strptr3;
@@ -276,7 +279,7 @@
 
         return(NULL);
 }
-
+#endif
 /*
  *	Returns 1 if pfx is a prefix of str.
  *
