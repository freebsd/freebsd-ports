--- src/common/lpf.c.orig	Wed Apr 16 03:37:42 2003
+++ src/common/lpf.c	Thu Dec 18 18:58:29 2003
@@ -188,7 +188,7 @@
 int crlf;	/* change lf to CRLF */
 
 void getargs( int argc, char *argv[], char *envp[] );
-void log( char *msg, ... );
+void lpf_log( char *msg, ... );
 void logerr( char *msg, ... );
 void logerr_die( char *msg, ... );
 void fatal( char *msg, ... );
@@ -312,9 +312,9 @@
 }
 
 #ifdef HAVE_STDARGS
-void log(char *msg, ...)
+void lpf_log(char *msg, ...)
 #else
-void log( va_alist ) va_dcl
+void lpf_log( va_alist ) va_dcl
 #endif
 {
 #ifndef HAVE_STDARGS
