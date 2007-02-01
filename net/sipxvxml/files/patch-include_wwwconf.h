--- ./include/wwwconf.h.orig	Fri Dec 29 10:57:47 2006
+++ ./include/wwwconf.h	Fri Dec 29 10:58:09 2006
@@ -348,7 +348,7 @@
 #define HAVE_LIMITS_H 1
 
 /* Define if you have the <malloc.h> header file.  */
-#define HAVE_MALLOC_H 1
+/* #undef HAVE_MALLOC_H  */
 
 /* Define if you have the <manifest.h> header file.  */
 /* #undef HAVE_MANIFEST_H */
