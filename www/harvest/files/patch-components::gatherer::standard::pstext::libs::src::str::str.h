--- ./components/gatherer/standard/pstext/libs/src/str/str.h.orig	Sun Mar 16 22:07:27 1997
+++ ./components/gatherer/standard/pstext/libs/src/str/str.h	Fri Aug  1 13:47:57 2003
@@ -11,9 +11,11 @@
 /*
  * str.h,v 1.1.1.1 1994/04/26 19:08:12 hardy Exp
  */
-
+#ifdef __STRICT_ANSI__
+#include <stdarg.h>
+#else
 #include <varargs.h>
-
+#endif
 
 #ifdef __ARGS
 #undef __ARGS
@@ -25,21 +27,32 @@
 #   define __ARGS( s )               ()
 #endif
 
+// void strx_print( int ccp, char *buf, int len, char *format, ... )
+// char *strx_sprint( char *buf, int len, char *format, ... )
+// int strx_nprint( char *buf, int len, char *format, ... )
+// void str_print( int ccp, char *buf, char *format, ... )
+// char *str_sprint( char *buf, char *format, ... )
+// int str_nprint( char *buf, char *format, ... )
+
 
 /*
  * strprint(3) functions
  */
+
+#ifndef __STRICT_ANSI__
+void strx_print __ARGS( ( int *count, char *buf, int len, char *fmt, ... ) ) ;
+int strx_nprint __ARGS( ( char *buf, int len, char *fmt, ... ) ) ;
+void str_print __ARGS( ( int *count, char *buf, char *fmt, ... ) ) ;
+char *strx_sprint __ARGS( ( char *buf, int len, char *fmt, ... ) ) ;
+int str_nprintv __ARGS( ( char *buf, char *fmt, va_list ) ) ;
 char *str_sprint __ARGS( ( char *buf, char *fmt, ... ) ) ;
 int str_nprint __ARGS( ( char *buf, char *fmt, ... ) ) ;
-void str_print __ARGS( ( int *count, char *buf, char *fmt, ... ) ) ;
+#endif
+
 
 char *str_sprintv __ARGS( ( char *buf, char *fmt, va_list ) ) ;
-int str_nprintv __ARGS( ( char *buf, char *fmt, va_list ) ) ;
 void str_printv __ARGS( ( int *count, char *buf, char *fmt, va_list ) ) ;
 
-char *strx_sprint __ARGS( ( char *buf, int len, char *fmt, ... ) ) ;
-int strx_nprint __ARGS( ( char *buf, int len, char *fmt, ... ) ) ;
-void strx_print __ARGS( ( int *count, char *buf, int len, char *fmt, ... ) ) ;
 
 char *strx_sprintv __ARGS( ( char *buf, int len, char *fmt, va_list ) ) ;
 int strx_nprintv __ARGS( ( char *buf, int len, char *fmt, va_list ) ) ;
