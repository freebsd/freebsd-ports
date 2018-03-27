--- avidemux_plugins/ADM_videoEncoder/x264/ADM_x264.cpp.orig	2016-01-29 08:47:25 UTC
+++ avidemux_plugins/ADM_videoEncoder/x264/ADM_x264.cpp
@@ -173,7 +173,7 @@ again:    
         //return false;
     }else
     {
-        //printf("[PPPP] x264 Incoming : %"PRIu64"us \n",image->Pts);    
+        //printf("[PPPP] x264 Incoming : %" PRIu64"us \n",image->Pts);    
         // 2-preamble   
         if(false==preAmble(image))
         {
@@ -289,11 +289,11 @@ bool x264Encoder::postAmble (ADMBitstrea
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
             if(picout->i_type!=X264_TYPE_B && picout->i_type!=X264_TYPE_BREF)
             {
@@ -341,7 +341,7 @@ bool x264Encoder::postAmble (ADMBitstrea
           ADM_error ("[x264] Unknown image type: %d\n", picout->i_type);
           //ADM_assert(0);
         }
-        //printf("[OOOO] x264 Outgoing : %"PRIu64"us \n",out->dts);    
+        //printf("[OOOO] x264 Outgoing : %" PRIu64"us \n",out->dts);    
         out->out_quantizer = picout->i_qpplus1;
         return true;
 }
