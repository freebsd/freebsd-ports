--- edflib.c.orig	2021-01-21 18:05:07 UTC
+++ edflib.c
@@ -46,7 +46,7 @@
 #define EDFLIB_MAXFILES  (64)
 
 
-#if defined(__APPLE__) || defined(__MACH__) || defined(__APPLE_CC__) || defined(__HAIKU__)
+#if defined(__APPLE__) || defined(__MACH__) || defined(__APPLE_CC__) || defined(__HAIKU__) || defined(__FreeBSD__)
 
 #define fopeno fopen
 
