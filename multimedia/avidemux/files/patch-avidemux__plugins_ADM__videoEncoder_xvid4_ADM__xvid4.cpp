--- avidemux_plugins/ADM_videoEncoder/xvid4/ADM_xvid4.cpp.orig	2016-01-29 08:47:25 UTC
+++ avidemux_plugins/ADM_videoEncoder/xvid4/ADM_xvid4.cpp
@@ -54,7 +54,7 @@ typedef enum
         RD_SQUARE = RD_HPEL_QPEL_8 | XVID_ME_EXTSEARCH_RD
 } RateDistortionMode;
 
-uint32_t rdMode[5]=
+int32_t rdMode[5]=
 {
     RD_NONE,
     RD_DCT_ME,
@@ -332,7 +332,7 @@ again:    
     // Store Pts/DTS
     ADM_timeMapping map; // Store real PTS <->lav value mapping
     map.realTS=image->Pts+getEncoderDelay();
-    aprintf("Pushing fn=%d Time=%"PRIu64"\n",frameNum,map.realTS);
+    aprintf("Pushing fn=%d Time=%" PRIu64"\n",frameNum,map.realTS);
    
     map.internalTS=frameNum++;
     mapper.push_back(map);
