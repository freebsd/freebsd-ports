Index: libgai/unp.h
diff -u libgai/unp.h.orig libgai/unp.h
--- libgai/unp.h.orig	Mon Sep 15 04:49:59 1997
+++ libgai/unp.h	Thu Oct 30 00:31:12 2003
@@ -58,6 +58,13 @@
 # include	<pthread.h>
 #endif
 
+#ifndef	EAI_ADDRFAMILY
+#define	EAI_ADDRFAMILY	1
+#endif
+#ifndef	EAI_NODATA
+#define	EAI_NODATA	7
+#endif
+
 /* OSF/1 actually disables recv() and send() in <sys/socket.h> */
 #ifdef	__osf__
 #undef	recv
