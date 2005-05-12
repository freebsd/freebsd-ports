--- libavcodec/x264.c.orig	Sun May  1 16:15:23 2005
+++ libavcodec/x264.c	Sun May  1 16:14:58 2005
@@ -19,6 +19,7 @@
 
 #include "avcodec.h"
 #include <x264.h>
+#include <math.h>
 
 typedef struct X264Context {
     x264_param_t params;
