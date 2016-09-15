--- md5/md5.c.orig	2016-09-07 23:21:14 UTC
+++ md5/md5.c
@@ -48,7 +48,7 @@
 #include <string.h>
 
 /* endianness check using glibc endian.h */
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 # include <machine/endian.h>
 #else
 # include <endian.h>
