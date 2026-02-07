--- msvmocas.c.orig	2010-05-05 08:55:55.000000000 -0400
+++ msvmocas.c	2011-10-06 05:20:07.000000000 -0400
@@ -91,6 +91,8 @@
   total_time = get_time();
 
   /* init */
+  input_fname = NULL;
+  model_fname= NULL;
   data_X = NULL;
   data_y = NULL;
   W = NULL;
@@ -508,6 +510,8 @@
 
 clean_up:
 
+  free(input_fname);
+  free(model_fname);
   mxDestroyArray(data_X);
   mxFree(data_y);
   mxFree(W);
