--- ./libs/libmythdvdnav/dvdnav_internal.h.orig	2008-03-07 20:03:12.000000000 -0500
+++ ./libs/libmythdvdnav/dvdnav_internal.h	2009-02-23 09:59:26.000000000 -0500
@@ -62,6 +62,9 @@
 #else
 
 #include <pthread.h>
+#if defined(__FreeBSD__)
+#define lseek64 lseek
+#endif
 
 #endif /* WIN32 */
 
