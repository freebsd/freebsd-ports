--- pyedflib/_extensions/c/edflib.c.orig	2022-02-22 07:57:42 UTC
+++ pyedflib/_extensions/c/edflib.c
@@ -46,7 +46,7 @@
 #define EDFLIB_MAXFILES  (64)
 
 
-#if defined(__APPLE__) || defined(__MACH__) || defined(__APPLE_CC__) || defined(__HAIKU__)
+#if defined(__APPLE__) || defined(__MACH__) || defined(__APPLE_CC__) || defined(__HAIKU__) || defined(__FreeBSD__)
 
 #define fopeno fopen
 
