--- compfile.c.orig	Thu Nov 25 22:22:28 1999
+++ compfile.c	Thu Jan 27 14:36:31 2000
@@ -207,7 +207,7 @@
  * version;
  */
 
-#if ( defined(sun) && defined(__svr4__) )
+#if ( defined(sun) && defined(__svr4__) || defined(__FreeBSD__) )
 #include <dirent.h>
 #else
 #include <sys/dir.h>
