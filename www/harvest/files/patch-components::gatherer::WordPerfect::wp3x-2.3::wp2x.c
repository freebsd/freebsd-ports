--- components/gatherer/WordPerfect/wp2x-2.3/wp2x.c.orig	Sat Nov 16 08:09:53 2002
+++ components/gatherer/WordPerfect/wp2x-2.3/wp2x.c	Sat Nov 23 04:42:43 2002
@@ -151,7 +151,7 @@
 #include "patchlevel.h"
 
 /* Some platforms do not define these externals in stdlib.h */
-#ifndef __CYGWIN__
+#if !defined(__CYGWIN__) && !defined(__FreeBSD__)
 #if NEED_SYS_ERRLIST || __GLIBC__
 extern char *Cdecl sys_errlist[];
 #endif
