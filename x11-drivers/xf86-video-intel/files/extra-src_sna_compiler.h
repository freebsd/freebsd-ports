--- src/sna/compiler.h.orig	2013-03-12 12:48:29.745101779 +0100
+++ src/sna/compiler.h	2013-03-12 12:48:52.857102997 +0100
@@ -37,7 +37,6 @@
 #define must_check __attribute__((warn_unused_result))
 #define constant __attribute__((const))
 #define pure __attribute__((pure))
-#define __packed__ __attribute__((__packed__))
 #define flatten __attribute__((flatten))
 #else
 #define likely(expr) (expr)
@@ -48,7 +47,6 @@
 #define must_check
 #define constant
 #define pure
-#define __packed__
 #define flatten
 #endif
 
