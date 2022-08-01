--- edflib.c.orig	2022-07-16 07:26:18 UTC
+++ edflib.c
@@ -38,7 +38,7 @@
 #define EDFLIB_VERSION  (122)
 #define EDFLIB_MAXFILES  (64)
 
-#if defined(__APPLE__) || defined(__MACH__) || defined(__APPLE_CC__) || defined(__HAIKU__) || defined(__ANDROID__)
+#if defined(__APPLE__) || defined(__MACH__) || defined(__APPLE_CC__) || defined(__HAIKU__) || defined(__ANDROID__) || defined(__FreeBSD__)
 
 #define fopeno fopen
 
