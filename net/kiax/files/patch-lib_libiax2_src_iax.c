--- lib/libiax2/src/iax.c.orig	Thu May 25 18:42:18 2006
+++ lib/libiax2/src/iax.c	Thu May 25 18:44:26 2006
@@ -59,14 +59,12 @@ void gettimeofday(struct timeval *tv, vo
 #include <arpa/inet.h>
 #include <time.h>
 
-#ifndef MACOSX
+#if !defined(MACOSX) && !defined(__FreeBSD__)
 #include <malloc.h>
 #ifndef SOLARIS
-#if !defined(__NetBSD__) && !defined(__FreeBSD__)
 #include <error.h>
 #endif
 #endif
-#endif
  
  #endif
 
@@ -97,7 +95,7 @@ void gettimeofday(struct timeval *tv, vo
 #ifdef SOLARIS
 #define IAX_SOCKOPTS MSG_DONTWAIT
 #else
-#ifdef __NetBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 #define IAX_SOCKOPTS MSG_DONTWAIT
 #else  /* Linux and others */
 #define IAX_SOCKOPTS MSG_DONTWAIT | MSG_NOSIGNAL
