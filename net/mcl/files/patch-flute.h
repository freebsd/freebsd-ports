--- flute/flute.h.orig	Wed Jan  7 11:13:20 2004
+++ flute/flute.h	Wed Jan  7 11:15:28 2004
@@ -69,6 +69,10 @@
 #elif defined(SOLARIS) || defined(IRIX) || defined(WIN32)
 
 #define	sighandler_t	void (*)(int)
+
+#elif defined(FREEBSD)
+#define sighandler_t   sig_t
+
 #endif
 
 
