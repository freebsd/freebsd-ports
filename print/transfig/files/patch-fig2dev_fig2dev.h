
$FreeBSD$

--- fig2dev/fig2dev.h.orig	Thu Aug 15 21:56:05 2002
+++ fig2dev/fig2dev.h	Thu Aug 15 21:56:40 2002
@@ -186,7 +186,7 @@
 #endif /* MAXPATHLEN */
 #endif /* PATH_MAX */
 
-#ifndef __NetBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 extern int		sys_nerr, errno;
 #endif
 
