--- global.h.orig	2025-09-08 04:16:58 UTC
+++ global.h
@@ -58,7 +58,7 @@
 
 #include <stdio.h>
 
-#if defined(__APPLE__) || defined(__MACH__) || defined(__APPLE_CC__) || defined(__HAIKU__)
+#if defined(__APPLE__) || defined(__MACH__) || defined(__APPLE_CC__) || defined(__HAIKU__) || defined(__FreeBSD__)
 #define fopeno fopen
 #else
 #define fseeko fseeko64
