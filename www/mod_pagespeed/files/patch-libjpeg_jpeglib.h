--- ./third_party/libjpeg/jpeglib.h.orig	2012-07-12 20:18:05.000000000 +0000
+++ ./third_party/libjpeg/jpeglib.h	2012-07-12 20:19:07.000000000 +0000
@@ -14,6 +14,8 @@
 #ifndef JPEGLIB_H
 #define JPEGLIB_H
 
+#include <stdio.h>
+
 /*
  * First we include the configuration files that record how this
  * installation of the JPEG library is set up.  jconfig.h can be
