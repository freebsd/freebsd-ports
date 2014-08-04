--- mkpasswd.orig	2014-06-08 17:57:46.000000000 +0200
+++ mkpasswd.c	2014-06-08 17:58:02.000000000 +0200
@@ -17,7 +17,9 @@
  */
 
 /* for crypt, snprintf and strcasecmp */
+#ifndef __FreeBSD__
 #define _XOPEN_SOURCE 500
+#endif
 #define _BSD_SOURCE 1
 #define __EXTENSIONS__ 1
 
