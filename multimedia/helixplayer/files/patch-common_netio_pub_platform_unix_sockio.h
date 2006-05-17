--- ./common/netio/pub/platform/unix/sockio.h.orig	Fri Jul  9 03:46:54 2004
+++ ./common/netio/pub/platform/unix/sockio.h	Fri Sep 10 21:59:06 2004
@@ -92,7 +92,7 @@
 
 #if defined (_AIX42)
 #define HX_SOCKLEN_T size_t
-#elif defined(_AIX43) || defined(_FREEBSD5) || defined(_FREEBSD4) || defined(_OPENBSD) ||defined(_NETBSD) || defined(_LINUX) || (defined (__GNUC__) && defined(_SOLARIS))
+#elif defined(_AIX43) || defined(_FREEBSD7) || defined(_FREEBSD6) || defined(_FREEBSD5) || defined(_FREEBSD4) || defined(_OPENBSD) ||defined(_NETBSD) || defined(_LINUX) || (defined (__GNUC__) && defined(_SOLARIS))
 #define HX_SOCKLEN_T socklen_t
 #else
 #define HX_SOCKLEN_T int
