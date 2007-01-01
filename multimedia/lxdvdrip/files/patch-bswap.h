--- bswap.h.orig	Fri Dec 15 14:17:04 2006
+++ bswap.h	Fri Dec 15 14:19:58 2006
@@ -29,7 +29,7 @@
 #else 
 
 /* For __FreeBSD_version */
-#if defined(HAVE_SYS_PARAM_H)
+#if defined(HAVE_SYS_PARAM_H) || ((defined(__unix__) || defined(unix)) && !defined(USG))
 #include <sys/param.h>
 #endif
 
