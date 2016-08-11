Index: libgai/unp.h
--- libgai/unp.h.orig	1997-09-14 19:49:59 UTC
+++ libgai/unp.h
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
