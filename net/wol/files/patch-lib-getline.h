--- lib/getline.h.orig	2009-03-19 21:29:20.290594165 +0000
+++ lib/getline.h	2009-03-19 21:29:39.070549165 +0000
@@ -28,10 +28,10 @@
 # endif
 
 # if __GLIBC__ < 2
-int
+ssize_t
 getline PARAMS ((char **_lineptr, size_t *_n, FILE *_stream));
 
-int
+ssize_t
 getdelim PARAMS ((char **_lineptr, size_t *_n, int _delimiter, FILE *_stream));
 # endif
 
