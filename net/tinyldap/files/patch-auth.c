--- auth.c.orig	2008-04-25 13:09:34.000000000 +0200
+++ auth.c	2009-11-22 22:28:37.000000000 +0100
@@ -2,11 +2,15 @@
 #ifdef __dietlibc__
 #include <md5.h>
 #else
+#ifdef __FreeBSD__
+#include <md5.h>
+#else
 #include <openssl/md5.h>
 #define MD5Init MD5_Init
 #define MD5Update MD5_Update
 #define MD5Final MD5_Final
 #endif
+#endif
 #define _XOPEN_SOURCE
 #include <unistd.h>
 #include <stdlib.h>
