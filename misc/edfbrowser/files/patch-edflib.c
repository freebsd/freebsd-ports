--- edflib.c.orig	2022-06-20 06:42:24 UTC
+++ edflib.c
@@ -38,7 +38,7 @@
 #define EDFLIB_VERSION  (121)
 #define EDFLIB_MAXFILES  (64)
 
-#if defined(__APPLE__) || defined(__MACH__) || defined(__APPLE_CC__) || defined(__HAIKU__)
+#if defined(__APPLE__) || defined(__MACH__) || defined(__APPLE_CC__) || defined(__HAIKU__) || defined(__FreeBSD__)
 
 #define fopeno fopen
 
