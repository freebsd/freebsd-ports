--- endian.hh.orig	2014-11-08 22:55:49.000000000 +0800
+++ endian.hh	2014-11-08 22:56:01.000000000 +0800
@@ -6,7 +6,7 @@
 
 #include <stdint.h>
 #include <arpa/inet.h>
-#ifdef __APPLE__
+#if defined(__APPLE_) || defined(__FreeBSD__)
 #include <machine/endian.h>
 #else
 #include <endian.h>
