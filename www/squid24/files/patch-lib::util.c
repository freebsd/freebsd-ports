--- lib/util.c.orig	Sat Dec 14 17:04:56 2002
+++ lib/util.c	Sat Dec 14 17:05:04 2002
@@ -76,7 +76,7 @@
 static char msg[128];
 
 #if !defined(__CYGWIN__)
-extern int sys_nerr;
+extern const int sys_nerr;
 #else
 #define sys_nerr _sys_nerr
 #endif
