--- mkpasswd.c.orig	2020-01-09 21:08:11 UTC
+++ mkpasswd.c
@@ -17,7 +17,6 @@
  */
 
 /* for crypt, snprintf and strcasecmp */
-#define _XOPEN_SOURCE 500
 #define _BSD_SOURCE 1
 #define _DEFAULT_SOURCE 1
 #define __EXTENSIONS__ 1
