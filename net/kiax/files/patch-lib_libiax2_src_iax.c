--- lib/libiax2/src/iax.c.orig	Sun Nov 13 13:59:36 2005
+++ lib/libiax2/src/iax.c	Sun Nov 13 14:21:46 2005
@@ -53,11 +53,13 @@
 #include <time.h>
 
 #ifndef MACOSX
+#ifndef __FreeBSD__
 #include <malloc.h>
 #ifndef SOLARIS
 #include <error.h>
 #endif
 #endif
+#endif
 
 #endif
 
@@ -85,10 +87,14 @@
 #ifdef MACOSX
 #define IAX_SOCKOPTS MSG_DONTWAIT
 #else
+#ifdef __FreeBSD__
+#define IAX_SOCKOPTS MSG_DONTWAIT
+#else
 #ifdef SOLARIS
 #define IAX_SOCKOPTS MSG_DONTWAIT
 #else  /* Linux and others */
 #define IAX_SOCKOPTS MSG_DONTWAIT | MSG_NOSIGNAL
+#endif
 #endif
 #endif
 #endif
