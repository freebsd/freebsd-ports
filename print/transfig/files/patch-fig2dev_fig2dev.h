--- fig2dev/fig2dev.h.orig	Thu Dec 19 07:45:28 2002
+++ fig2dev/fig2dev.h	Tue Jan  7 20:08:45 2003
@@ -210,7 +210,7 @@
 #endif /* MAXPATHLEN */
 #endif /* PATH_MAX */
 
-#if ( !defined(__NetBSD__) && !defined(__DARWIN__))
+#if ( !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__DARWIN__))
 extern int		sys_nerr, errno;
 #endif
 
