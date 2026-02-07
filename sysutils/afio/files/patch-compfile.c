--- compfile.c.orig	2018-11-30 14:25:04 UTC
+++ compfile.c
@@ -224,7 +224,7 @@ void waitforgzip()
  * version;
  */
 
-#if ( defined(sun) && defined(__svr4__) ) || defined(__CYGWIN32__)
+#if ( defined(sun) && defined(__svr4__) ) || defined(__FreeBSD__)
 #include <dirent.h>
 #else
 #include <sys/dir.h>
