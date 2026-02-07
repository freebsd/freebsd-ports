--- src/common/log.c.orig	2004-08-26 20:56:20 UTC
+++ src/common/log.c
@@ -69,8 +69,8 @@ static int must_openlog = TRUE;
 char *strerror(int errnum)
 {
 #ifndef OS2
-    extern int sys_nerr;
 # ifndef __FreeBSD__
+    extern int sys_nerr;
     extern char *sys_errlist[];
 # endif
 #endif
