--- global.h.orig	2022-06-20 06:40:34 UTC
+++ global.h
@@ -54,7 +54,7 @@
 
 #include <stdio.h>
 
-#if defined(__APPLE__) || defined(__MACH__) || defined(__APPLE_CC__) || defined(__HAIKU__)
+#if defined(__APPLE__) || defined(__MACH__) || defined(__APPLE_CC__) || defined(__HAIKU__) || defined(__FreeBSD__)
 
 #define fopeno fopen
 
