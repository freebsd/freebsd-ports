--- movtar_yuv422.c.orig	2007-12-12 22:28:38.000000000 +0100
+++ movtar_yuv422.c	2007-12-12 22:29:00.000000000 +0100
@@ -32,6 +32,7 @@
 */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <jpeglib.h>
 
 #define MAXPIXELS (1024*1024)  /* Maximum size of final image */
