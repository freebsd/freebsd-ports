--- md5.h.orig	Mon Jan 12 00:13:05 1998
+++ md5.h	Sun Dec  8 11:50:50 2002
@@ -1,7 +1,7 @@
 #ifndef MD5_H
 #define MD5_H
 
-#ifdef __alpha
+#if defined(__alpha) || defined(__sparc64__) || defined(__ia64__) || defined(__amd64__)
 typedef unsigned int uint32;
 #else
 typedef unsigned long uint32;
