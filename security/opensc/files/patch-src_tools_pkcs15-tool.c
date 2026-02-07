--- src/tools/pkcs15-tool.c.orig	2018-01-31 08:43:55 UTC
+++ src/tools/pkcs15-tool.c
@@ -20,7 +20,7 @@
  */
 #include "config.h"
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #define _XOPEN_SOURCE 600
 #else
 #define _XOPEN_SOURCE 500
