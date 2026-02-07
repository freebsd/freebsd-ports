--- global.h.orig	Mon Jan 12 00:13:04 1998
+++ global.h	Sun Dec  8 11:49:27 2002
@@ -1,6 +1,6 @@
 /* Needed by RSAREF */
 
-#ifdef __alpha
+#if defined(__alpha) || defined(__sparc64__) || defined(__ia64__) || defined(__amd64__)
 typedef unsigned UINT4;
 #else
 typedef unsigned long UINT4;
