
$FreeBSD$

--- directory/c-sdk/ldap/include/portable.h	2001/07/17 16:08:33	1.1
+++ directory/c-sdk/ldap/include/portable.h	2001/07/17 16:10:15
@@ -249,7 +249,7 @@
     defined(NCR) || defined(OSF1) || defined(NEC) || defined(VMS) || \
     ( defined(HPUX10) && !defined(_REENTRANT)) || defined(HPUX11) || \
     defined(UnixWare) || defined(LINUX) || defined(NETBSD) || \
-    (defined(AIX) && !defined(USE_REENTRANT_LIBC))
+    defined (FREEBSD) || (defined(AIX) && !defined(USE_REENTRANT_LIBC))
 #define GETHOSTBYNAME( n, r, b, l, e )  gethostbyname( n )
 #elif defined(AIX)
 /* Maybe this is for another version of AIX?
