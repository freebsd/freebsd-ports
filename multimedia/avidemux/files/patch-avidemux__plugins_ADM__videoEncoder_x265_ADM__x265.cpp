--- avidemux_plugins/ADM_videoEncoder/x265/ADM_x265.cpp.orig	2016-01-29 08:47:25 UTC
+++ avidemux_plugins/ADM_videoEncoder/x265/ADM_x265.cpp
@@ -284,11 +284,11 @@ bool x265Encoder::postAmble (ADMBitstrea
         }
         //------
         aprintf("encoder delay=%d, pic out dts=%d picout pts=%d\n",getEncoderDelay(),picout->i_dts,picout->i_pts);
-        aprintf("pts = %"PRIu64", dts=%"PRIu64", pts+delay=%"PRIu64" delta=%"PRIu64"\n",picout->i_pts,out->dts,out->pts,
+        aprintf("pts = %" PRIu64", dts=%" PRIu64", pts+delay=%" PRIu64" delta=%" PRIu64"\n",picout->i_pts,out->dts,out->pts,
                     out->pts-out->dts);
         if(out->dts>out->pts)
         {
-            ADM_warning("DTS > PTS, that can happen when there are holes in the source (%"PRIu64"/%"PRIu64")\n",
+            ADM_warning("DTS > PTS, that can happen when there are holes in the source (%" PRIu64"/%" PRIu64")\n",
                         out->dts,out->pts);
             if(picout->sliceType!=X265_TYPE_B && picout->sliceType!=X265_TYPE_BREF)
             {
