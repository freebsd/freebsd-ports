--- ./components/gatherer/standard/pstext/libs/src/sio/sio.h.orig	Sun Mar 16 22:07:04 1997
+++ ./components/gatherer/standard/pstext/libs/src/sio/sio.h	Fri Aug  1 13:24:57 2003
@@ -12,7 +12,11 @@
 #define __SIO_H
 
 #include <errno.h>
+#if defined(__STRICT_ANSI__)
+#include <stdarg.h>
+#else
 #include <varargs.h>
+#endif
 
 /*
  * Naming conventions:
@@ -240,8 +244,10 @@
  */
 int Swrite __ARGS( ( int fd, char *buf, int nbytes ) ) ;
 int Sputc __ARGS( ( int fd, char c ) ) ;
-int Sprint __ARGS( ( int fd, char *format, ... ) ) ;
-int Sprintv __ARGS( ( int fd, char *format, va_list ) ) ;
+#ifndef __STRICT_ANSI__
+int Sprint __ARGS( ( int fd, char *format , ...) ) ;
+#endif
+int Sprintv __ARGS( ( int fd, char *format, va_args ) ) ;
 
 /*
  * other functions
