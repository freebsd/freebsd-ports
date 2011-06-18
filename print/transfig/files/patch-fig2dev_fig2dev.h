--- fig2dev/fig2dev.h.orig	2010-03-16 11:53:20.000000000 -0700
+++ fig2dev/fig2dev.h	2011-06-16 22:23:27.000000000 -0700
@@ -214,7 +214,7 @@
 #endif /* MAXPATHLEN */
 #endif /* PATH_MAX */
 
-#if ( !defined(__NetBSD__) && !defined(__DARWIN__) && !defined(__FreeBSD) )
+#if ( !defined(__NetBSD__) && !defined(__DARWIN__) && !defined(__FreeBSD__) )
 extern int		sys_nerr, errno;
 #endif
 
