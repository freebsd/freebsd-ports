--- src/common/log.c.orig	Sun Feb 16 16:38:56 2003
+++ src/common/log.c	Sat Aug 21 11:10:09 2004
@@ -69,8 +69,8 @@
 char *strerror(int errnum)
 {
 #ifndef OS2
-    extern int sys_nerr;
 # ifndef __FreeBSD__
+    extern int sys_nerr;
     extern char *sys_errlist[];
 # endif
 #endif
@@ -280,8 +280,10 @@
     
     BUF_COPY(logprog, name);
 
+#if 0 /**NOT NEEDED AND SECURITY RISK**/
     if( (p = getenv("LOGFILE")) )
        log_file(p);
     if( (p = getenv("FIDOGATE_LOGFILE")) )
        log_file(p);
+#endif
 }
