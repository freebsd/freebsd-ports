--- lib/strerror.c.orig	Sat Dec 14 17:04:03 2002
+++ lib/strerror.c	Sat Dec 14 17:04:19 2002
@@ -38,7 +38,7 @@
 #include <errno.h>
 #endif
 
-extern int sys_nerr;
+extern const int sys_nerr;
 #if NEED_SYS_ERRLIST && !defined(_SQUID_NETBSD_)
 extern char *sys_errlist[];
 #endif
