--- endeavour/string.cpp.orig	Tue Jan 29 17:05:25 2002
+++ endeavour/string.cpp	Tue Jan 29 17:11:26 2002
@@ -35,7 +35,7 @@
 #endif	/* __MSW__ */
 
 const char *strseekblank(const char *s);
-const char *strcasestr(const char *haystack, const char *needle);
+// const char *strcasestr(const char *haystack, const char *needle);
 int strpfx(const char *str, const char *pfx);
 int strcasepfx(const char *str, const char *pfx);
 void strtoupper(char *s);
@@ -219,6 +219,7 @@
  *	Case insensitive version of strstr(). Returns the pointer to
  *	needle in haystack if found or NULL on no match.
  */
+#ifndef __FreeBSD__
 const char *strcasestr(const char *haystack, const char *needle)
 {
 	const char *strptr1, *strptr2, *strptr3;
@@ -276,7 +277,7 @@
 
         return(NULL);
 }
-
+#endif
 /*
  *	Returns 1 if pfx is a prefix of str.
  *
