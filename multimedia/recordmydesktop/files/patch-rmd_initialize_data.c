--- src/rmd_initialize_data.c.orig	2012-11-05 13:28:29.000000000 +0800
+++ src/rmd_initialize_data.c	2012-11-05 13:28:57.000000000 +0800
@@ -224,7 +224,7 @@
     args->channels             = 1;
     args->frequency            = 22050;
     args->buffsize             = 4096;
-    args->v_bitrate            = 45000;
+    args->v_bitrate            = 0;
     args->v_quality            = 63;
     args->s_quality            = 10;
 
