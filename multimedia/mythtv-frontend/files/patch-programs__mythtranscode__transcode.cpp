--- programs/mythtranscode/transcode.cpp.orig	2012-03-19 06:39:10.000000000 +0100
+++ programs/mythtranscode/transcode.cpp	2012-03-24 18:25:25.121052981 +0100
@@ -484,7 +484,7 @@
         {
             return false;
         }
-        else if (abs(audioFramesToCut - frames) < audioFramesToCut)
+        else if (llabs(audioFramesToCut - frames) < audioFramesToCut)
         {
             // Drop the packet containing these frames if doing
             // so gets us closer to zero left to drop
