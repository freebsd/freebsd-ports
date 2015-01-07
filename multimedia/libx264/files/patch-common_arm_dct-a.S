--- common/arm/dct-a.S.orig	2014-08-27 20:45:08 UTC
+++ common/arm/dct-a.S
@@ -82,7 +82,7 @@ function x264_dct4x4dc_neon
     vrhadd.s16      d3,  d6,  d7
     vst1.64         {d0-d3}, [r0,:128]
     bx              lr
-.endfunc
+endfunc
 
 function x264_idct4x4dc_neon
     vld1.64         {d0-d3}, [r0,:128]
@@ -94,7 +94,7 @@ function x264_idct4x4dc_neon
     HADAMARD        2, sumsub, d3, d2, d6, d7
     vst1.64         {d0-d3}, [r0,:128]
     bx              lr
-.endfunc
+endfunc
 
 
 .macro DCT_1D d0 d1 d2 d3  d4 d5 d6 d7
@@ -129,7 +129,7 @@ function x264_sub4x4_dct_neon
     DCT_1D          d4, d5, d6, d7, d0, d1, d2, d3
     vst1.64         {d4-d7}, [r0,:128]
     bx              lr
-.endfunc
+endfunc
 
 function x264_sub8x4_dct_neon, export=0
     vld1.64         {d0}, [r1,:64], r3
@@ -165,7 +165,7 @@ function x264_sub8x4_dct_neon, export=0
     vst1.64         {d4-d5}, [r0,:128]!
     vst1.64         {d6-d7}, [r0,:128]!
     bx              lr
-.endfunc
+endfunc
 
 function x264_sub8x8_dct_neon
     push            {lr}
@@ -174,7 +174,7 @@ function x264_sub8x8_dct_neon
     bl              x264_sub8x4_dct_neon
     pop             {lr}
     b               x264_sub8x4_dct_neon
-.endfunc
+endfunc
 
 function x264_sub16x16_dct_neon
     push            {lr}
@@ -195,7 +195,7 @@ function x264_sub16x16_dct_neon
     bl              x264_sub8x4_dct_neon
     pop             {lr}
     b               x264_sub8x4_dct_neon
-.endfunc
+endfunc
 
 
 .macro DCT8_1D type
@@ -279,7 +279,7 @@ function x264_sub8x8_dct8_neon
     vst1.64         {d24-d27}, [r0,:128]!
     vst1.64         {d28-d31}, [r0,:128]!
     bx              lr
-.endfunc
+endfunc
 
 function x264_sub16x16_dct8_neon
     push            {lr}
@@ -294,7 +294,7 @@ function x264_sub16x16_dct8_neon
     sub             r1,  r1,  #FENC_STRIDE*8 - 8
     sub             r2,  r2,  #FDEC_STRIDE*8 - 8
     b               X(x264_sub8x8_dct8_neon)
-.endfunc
+endfunc
 
 
 // First part of IDCT (minus final SUMSUB_BA)
@@ -336,7 +336,7 @@ function x264_add4x4_idct_neon
     vst1.32         {d2[1]}, [r0,:32], r2
     vst1.32         {d2[0]}, [r0,:32], r2
     bx              lr
-.endfunc
+endfunc
 
 function x264_add8x4_idct_neon, export=0
     vld1.64         {d0-d3}, [r1,:128]!
@@ -376,7 +376,7 @@ function x264_add8x4_idct_neon, export=0
     vst1.32         {d2}, [r0,:64], r2
     vst1.32         {d3}, [r0,:64], r2
     bx              lr
-.endfunc
+endfunc
 
 function x264_add8x8_idct_neon
     mov             r2, #FDEC_STRIDE
@@ -384,7 +384,7 @@ function x264_add8x8_idct_neon
     bl              x264_add8x4_idct_neon
     mov             lr, ip
     b               x264_add8x4_idct_neon
-.endfunc
+endfunc
 
 function x264_add16x16_idct_neon
     mov             r2, #FDEC_STRIDE
@@ -401,7 +401,7 @@ function x264_add16x16_idct_neon
     bl              x264_add8x4_idct_neon
     mov             lr, ip
     b               x264_add8x4_idct_neon
-.endfunc
+endfunc
 
 
 .macro IDCT8_1D type
@@ -498,7 +498,7 @@ function x264_add8x8_idct8_neon
     vst1.64         {d6}, [r0,:64], r2
     vst1.64         {d7}, [r0,:64], r2
     bx              lr
-.endfunc
+endfunc
 
 function x264_add16x16_idct8_neon
     mov             ip,  lr
@@ -510,7 +510,7 @@ function x264_add16x16_idct8_neon
     sub             r0,  r0,  #8*FDEC_STRIDE-8
     mov             lr,  ip
     b               X(x264_add8x8_idct8_neon)
-.endfunc
+endfunc
 
 
 function x264_add8x8_idct_dc_neon
@@ -562,7 +562,7 @@ function x264_add8x8_idct_dc_neon
     vst1.64         {d6}, [r0,:64], r2
     vst1.64         {d7}, [r0,:64], r2
     bx              lr
-.endfunc
+endfunc
 
 .macro ADD16x4_IDCT_DC dc
     vld1.64         {d16-d17}, [r0,:128], r3
@@ -610,7 +610,7 @@ function x264_add16x16_idct_dc_neon
     ADD16x4_IDCT_DC d2
     ADD16x4_IDCT_DC d3
     bx              lr
-.endfunc
+endfunc
 
 function x264_sub8x8_dct_dc_neon
     mov             r3,  #FENC_STRIDE
@@ -658,7 +658,7 @@ function x264_sub8x8_dct_dc_neon
     vpadd.s16       d0,  d0,  d1
     vst1.64         {d0}, [r0,:64]
     bx              lr
-.endfunc
+endfunc
 
 
 function x264_zigzag_scan_4x4_frame_neon
@@ -671,4 +671,4 @@ function x264_zigzag_scan_4x4_frame_neon
     vtbl.8      d7, {d2-d3}, d19
     vst1.64     {d4-d7},   [r0,:128]
     bx          lr
-.endfunc
+endfunc
