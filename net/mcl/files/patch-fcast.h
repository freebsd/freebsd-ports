--- fcast/fcast.h.orig	Tue Jul 22 19:37:39 2003
+++ fcast/fcast.h	Wed Oct 15 16:59:13 2003
@@ -62,12 +62,16 @@
 #include "frecv.h"
 
 
+
 #if defined(LINUX) /* On Linux systems, signal handlers must be of __sighandler_t type */
 #define	sighandler_t	__sighandler_t
 
 #elif defined(SOLARIS) || defined(IRIX) || defined(WIN32)
-
 #define	sighandler_t	void (*)(int)
+
+#elif defined(FREEBSD)
+#define sighandler_t	sig_t
+
 #endif
 
 
