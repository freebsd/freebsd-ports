--- fig2dev/fig2dev.h.orig	Tue Jul 15 09:21:12 2003
+++ fig2dev/fig2dev.h
@@ -213,7 +213,7 @@
 #endif /* MAXPATHLEN */
 #endif /* PATH_MAX */
 
-#if ( !defined(__NetBSD__) && !defined(__DARWIN__))
+#if ( !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__DARWIN__))
 extern int		sys_nerr, errno;
 #endif
 
