--- include/includes.h.orig	Tue Jul  1 22:44:25 2003
+++ include/includes.h	Sun Aug  3 12:05:23 2003
@@ -1248,10 +1248,14 @@
 
 
 /* we need to use __va_copy() on some platforms */
-#ifdef HAVE_VA_COPY
+#ifdef HAVE__VA_COPY
 #define VA_COPY(dest, src) __va_copy(dest, src)
 #else
+#ifdef HAVE_VA_COPY
+#define VA_COPY(dest, src) va_copy(dest, src)
+#else
 #define VA_COPY(dest, src) (dest) = (src)
+#endif
 #endif
 
 #ifndef HAVE_TIMEGM

