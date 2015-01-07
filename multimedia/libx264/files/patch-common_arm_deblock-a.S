--- common/arm/deblock-a.S.orig	2014-08-27 20:45:08 UTC
+++ common/arm/deblock-a.S
@@ -142,7 +142,7 @@ function x264_deblock_v_luma_neon
 
     align_pop_regs
     bx              lr
-.endfunc
+endfunc
 
 function x264_deblock_h_luma_neon
     h264_loop_filter_start
@@ -194,7 +194,7 @@ function x264_deblock_h_luma_neon
 
     align_pop_regs
     bx              lr
-.endfunc
+endfunc
 
 .macro h264_loop_filter_chroma
     vdup.8          q11, r2         // alpha
@@ -255,7 +255,7 @@ function x264_deblock_v_chroma_neon
     vst2.8          {d0, d1},  [r0,:128], r1
 
     bx              lr
-.endfunc
+endfunc
 
 function x264_deblock_h_chroma_neon
     h264_loop_filter_start
@@ -303,7 +303,7 @@ function x264_deblock_h_chroma_neon
     vst1.8          {d3},  [r0], r1
 
     bx              lr
-.endfunc
+endfunc
 
 function x264_deblock_strength_neon
     ldr             ip,  [sp]
@@ -409,4 +409,4 @@ lists:
 
     vst1.8          {q8}, [r3,:128]     @ bs[0]
     bx              lr
-.endfunc
+endfunc
