
$FreeBSD$

--- jnlib/logging.c.orig	Thu Jun  8 11:49:51 2000
+++ jnlib/logging.c	Sat Nov 30 14:03:44 2002
@@ -226,14 +226,9 @@
 {
     va_list arg_ptr ;
 
-    if( !fmt ) {
-	do_logv( MY_LOG_BEGIN, NULL, NULL );
-    }
-    else {
-	va_start( arg_ptr, fmt ) ;
-	do_logv( MY_LOG_CONT, fmt, arg_ptr );
-	va_end(arg_ptr);
-    }
+    va_start( arg_ptr, fmt ) ;
+    do_logv( MY_LOG_CONT, fmt, arg_ptr );
+    va_end(arg_ptr);
 }
 
 
