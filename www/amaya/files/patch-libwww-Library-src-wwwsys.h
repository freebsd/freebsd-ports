--- ../../libwww/Library/src/wwwsys.h.orig	Fri Aug 12 20:41:18 2005
+++ ../../libwww/Library/src/wwwsys.h	Sun Aug 14 11:16:55 2005
@@ -1320,10 +1320,6 @@
 #define socerrno errno
 #endif
 
-#ifndef HAVE_STRERROR				  /* Otherwise use the table */
-extern char *sys_errlist[];
-extern int sys_nerr;
-#endif
 
 /*
 .
