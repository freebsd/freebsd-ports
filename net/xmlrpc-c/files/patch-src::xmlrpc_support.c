--- src/xmlrpc_support.c.orig	Sat Apr 14 03:25:08 2001
+++ src/xmlrpc_support.c	Tue Mar  2 23:39:39 2004
@@ -99,7 +99,7 @@
 }
 
 void xmlrpc_env_set_fault_formatted (xmlrpc_env* env, int code,
-				     char *format, ...)
+				     const char *format, ...)
 {
     va_list args;
     char buffer[ERROR_BUFFER_SZ];
