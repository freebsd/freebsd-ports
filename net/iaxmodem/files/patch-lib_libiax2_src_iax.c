--- lib/libiax2/src/iax.c.orig	Mon Jun 12 15:54:46 2006
+++ lib/libiax2/src/iax.c	Thu Jun 15 14:22:17 2006
@@ -44,6 +44,7 @@
 #else
 
 #include <netdb.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <sys/time.h>
@@ -64,9 +64,9 @@
 #include <arpa/inet.h>
 #include <time.h>
 
-#if !defined(MACOSX) && !defined(__OpenBSD__)
+#if !defined(MACOSX) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <malloc.h>
-#if !defined(SOLARIS)
+#if !defined(SOLARIS) && !defined(__FreeBSD__)
 #include <error.h>
 #endif
 #endif
@@ -97,7 +97,7 @@
 #ifdef MACOSX
 #define IAX_SOCKOPTS MSG_DONTWAIT
 #else
-#if defined(SOLARIS) || defined(__OpenBSD__)
+#if defined(SOLARIS) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #define IAX_SOCKOPTS MSG_DONTWAIT
 #else  /* Linux and others */
 #define IAX_SOCKOPTS MSG_DONTWAIT | MSG_NOSIGNAL
