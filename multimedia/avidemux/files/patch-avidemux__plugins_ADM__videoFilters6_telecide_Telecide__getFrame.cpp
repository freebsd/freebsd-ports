--- avidemux_plugins/ADM_videoFilters6/telecide/Telecide_getFrame.cpp.orig	2016-01-29 08:47:25 UTC
+++ avidemux_plugins/ADM_videoFilters6/telecide/Telecide_getFrame.cpp
@@ -240,7 +240,7 @@ teleCide *_param=&configuration;
                         {
                                 // The chosen frame doesn't match the prediction.
                                 if (predicted_metric == 0) mismatch = 0.0;
-                                else mismatch = (100.0*abs(predicted_metric - lowest))/predicted_metric;
+                                else mismatch = (100.0*abs((int)predicted_metric - (int)lowest))/predicted_metric;
                                 if (mismatch < gthresh)
                                 {
                                         // It's close enough, so use the predicted one.
@@ -283,7 +283,7 @@ teleCide *_param=&configuration;
                                         {
                                                 // The chosen frame doesn't match the prediction.
                                                 if (predicted_metric == 0) mismatch = 0.0;
-                                                else mismatch = (100.0*abs(predicted_metric - lowest))/predicted_metric;
+                                                else mismatch = (100.0*abs((int)predicted_metric - (int)lowest))/predicted_metric;
                                                 if ((int) mismatch <= gthresh)
                                                 {
                                                         // It's close enough, so use the predicted one.
@@ -394,7 +394,7 @@ teleCide *_param=&configuration;
         {
                 unsigned char *dstpp, *dstpn;
                 int v1, v2, z;
-                #warning blend in place is wrong!
+                //#warning blend in place is wrong!
                 final=dst;
                 // MeanX:We should copy here as we blend from source and destination
                 // for the moment we do it in place, it is wrong.
