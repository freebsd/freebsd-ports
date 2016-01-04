--- common/aarch64/deblock-a.S.orig	2016-01-04 11:21:40.265233000 +0000
+++ common/aarch64/deblock-a.S	2016-01-04 11:27:19.291080000 +0000
@@ -538,7 +538,7 @@
     ret
 endfunc
 
-.macro h264_loop_filter_chroma_intra, width=16
+.macro h264_loop_filter_chroma_intra width=16
     uabd            v26.16b, v16.16b, v17.16b  // abs(p0 - q0)
     uabd            v27.16b, v18.16b, v16.16b  // abs(p1 - p0)
     uabd            v28.16b, v19.16b, v17.16b  // abs(q1 - q0)
@@ -604,7 +604,7 @@
 
     transpose4x4.h  v18, v16, v17, v19, v26, v27, v28, v29
 
-    h264_loop_filter_chroma_intra, width=8
+    h264_loop_filter_chroma_intra width=8
 
     st2             {v16.h,v17.h}[0], [x0], x1
     st2             {v16.h,v17.h}[1], [x0], x1
