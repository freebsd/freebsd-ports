--- ./third_party/iccjpeg/iccjpeg.h.orig	2010-12-16 02:11:35.000000000 +0100
+++ ./third_party/iccjpeg/iccjpeg.h	2010-12-20 20:15:08.000000000 +0100
@@ -17,7 +17,7 @@
  */
 
 #include <stdio.h>		/* needed to define "FILE", "NULL" */
-#include "jpeglib.h"
+#include "../libjpeg/jpeglib.h"
 
 
 /*
