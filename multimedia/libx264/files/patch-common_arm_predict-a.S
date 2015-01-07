--- common/arm/predict-a.S.orig	2014-08-27 20:45:08 UTC
+++ common/arm/predict-a.S
@@ -77,7 +77,7 @@ function x264_predict_4x4_h_armv6
     add     ip, ip, ip, lsl #16
     str     ip, [r0, #3*FDEC_STRIDE]
     bx      lr
-.endfunc
+endfunc
 
 function x264_predict_4x4_v_armv6
     ldr     r1,  [r0, #0 - 1 * FDEC_STRIDE]
@@ -86,7 +86,7 @@ function x264_predict_4x4_v_armv6
     str     r1,  [r0, #0 + 2 * FDEC_STRIDE]
     str     r1,  [r0, #0 + 3 * FDEC_STRIDE]
     bx      lr
-.endfunc
+endfunc
 
 function x264_predict_4x4_dc_armv6
     mov     ip, #0
@@ -109,7 +109,7 @@ function x264_predict_4x4_dc_armv6
     str     r1, [r0, #2*FDEC_STRIDE]
     str     r1, [r0, #3*FDEC_STRIDE]
     bx      lr
-.endfunc
+endfunc
 
 function x264_predict_4x4_dc_top_neon
     mov         r12, #FDEC_STRIDE
@@ -124,7 +124,7 @@ function x264_predict_4x4_dc_top_neon
     vst1.32     d1[0], [r0,:32], r12
     vst1.32     d1[0], [r0,:32], r12
     bx          lr
-.endfunc
+endfunc
 
 // return a1 = (a1+2*b1+c1+2)>>2  a2 = (a2+2*b2+c2+2)>>2
 .macro PRED4x4_LOWPASS a1 b1 c1 a2 b2 c2 pb_1
@@ -167,7 +167,7 @@ function x264_predict_4x4_ddr_armv6
     add     r5, r5, r4, lsr #8
     str     r5, [r0, #3*FDEC_STRIDE]
     pop     {r4-r6,pc}
-.endfunc
+endfunc
 
 function x264_predict_4x4_ddl_neon
     sub         r0, #FDEC_STRIDE
@@ -186,7 +186,7 @@ function x264_predict_4x4_ddl_neon
     vst1.32     {d2[0]}, [r0,:32], ip
     vst1.32     {d3[0]}, [r0,:32], ip
     bx          lr
-.endfunc
+endfunc
 
 function x264_predict_8x8_dc_neon
     mov     ip, #0
@@ -210,7 +210,7 @@ function x264_predict_8x8_dc_neon
     vst1.64 {d0}, [r0,:64], ip
 .endr
     pop    {r4-r5,pc}
-.endfunc
+endfunc
 
 function x264_predict_8x8_h_neon
     add         r1, r1, #7
@@ -233,7 +233,7 @@ function x264_predict_8x8_h_neon
     vst1.64     {d6}, [r0,:64], ip
     vst1.64     {d7}, [r0,:64], ip
     bx          lr
-.endfunc
+endfunc
 
 function x264_predict_8x8_v_neon
     add         r1, r1, #16
@@ -243,7 +243,7 @@ function x264_predict_8x8_v_neon
     vst1.8      {d0}, [r0,:64], r12
 .endr
     bx          lr
-.endfunc
+endfunc
 
 function x264_predict_8x8_ddl_neon
     add         r1, #16
@@ -271,7 +271,7 @@ function x264_predict_8x8_ddl_neon
     vst1.8      d2, [r0,:64], r12
     vst1.8      d1, [r0,:64], r12
     bx          lr
-.endfunc
+endfunc
 
 function x264_predict_8x8_ddr_neon
     vld1.8      {d0-d3}, [r1,:128]
@@ -301,7 +301,7 @@ function x264_predict_8x8_ddr_neon
     vst1.8      {d4}, [r0,:64], r12
     vst1.8      {d5}, [r0,:64], r12
     bx          lr
-.endfunc
+endfunc
 
 function x264_predict_8x8_vl_neon
     add         r1, #16
@@ -332,7 +332,7 @@ function x264_predict_8x8_vl_neon
     vst1.8      {d3}, [r0,:64], r12
     vst1.8      {d2}, [r0,:64], r12
     bx          lr
-.endfunc
+endfunc
 
 function x264_predict_8x8_vr_neon
     add         r1, #8
@@ -364,7 +364,7 @@ function x264_predict_8x8_vr_neon
     vst1.8      {d6}, [r0,:64], r12
     vst1.8      {d3}, [r0,:64], r12
     bx          lr
-.endfunc
+endfunc
 
 function x264_predict_8x8_hd_neon
     mov         r12, #FDEC_STRIDE
@@ -397,7 +397,7 @@ function x264_predict_8x8_hd_neon
     vst1.8      {d16}, [r0,:64], r12
 
     bx          lr
-.endfunc
+endfunc
 
 function x264_predict_8x8_hu_neon
     mov         r12, #FDEC_STRIDE
@@ -430,7 +430,7 @@ function x264_predict_8x8_hu_neon
     vst1.8      {d7}, [r0,:64], r12
     vst1.8      {d17}, [r0,:64]
     bx          lr
-.endfunc
+endfunc
 
 function x264_predict_8x8c_dc_top_neon
     sub         r2,  r0,  #FDEC_STRIDE
@@ -443,7 +443,7 @@ function x264_predict_8x8c_dc_top_neon
     vdup.8      d0,  d0[0]
     vtrn.32     d0,  d1
     b           pred8x8_dc_end
-.endfunc
+endfunc
 
 function x264_predict_8x8c_dc_left_neon
     mov         r1,  #FDEC_STRIDE
@@ -455,7 +455,7 @@ function x264_predict_8x8c_dc_left_neon
     vdup.8      d1,  d0[1]
     vdup.8      d0,  d0[0]
     b           pred8x8_dc_end
-.endfunc
+endfunc
 
 function x264_predict_8x8c_dc_neon
     sub         r2,  r0,  #FDEC_STRIDE
@@ -481,7 +481,7 @@ pred8x8_dc_end:
     vst1.8      {d1}, [r2,:64], r1
 .endr
     bx          lr
-.endfunc
+endfunc
 
 function x264_predict_8x8c_h_neon
     sub         r1, r0, #1
@@ -493,7 +493,7 @@ function x264_predict_8x8c_h_neon
     vst1.64     {d2}, [r0,:64], ip
 .endr
     bx          lr
-.endfunc
+endfunc
 
 function x264_predict_8x8c_v_neon
     sub         r0, r0, #FDEC_STRIDE
@@ -503,7 +503,7 @@ function x264_predict_8x8c_v_neon
     vst1.64     {d0}, [r0,:64], ip
 .endr
     bx          lr
-.endfunc
+endfunc
 
 function x264_predict_8x8c_p_neon
     sub         r3,  r0,  #FDEC_STRIDE
@@ -556,7 +556,7 @@ function x264_predict_8x8c_p_neon
     subs        r3,  r3,  #1
     bne         1b
     bx          lr
-.endfunc
+endfunc
 
 
 function x264_predict_16x16_dc_top_neon
@@ -567,7 +567,7 @@ function x264_predict_16x16_dc_top_neon
     vrshrn.u16  d0,  q0,  #4
     vdup.8      q0,  d0[0]
     b           pred16x16_dc_end
-.endfunc
+endfunc
 
 function x264_predict_16x16_dc_left_neon
     mov         r1,  #FDEC_STRIDE
@@ -578,7 +578,7 @@ function x264_predict_16x16_dc_left_neon
     vrshrn.u16  d0,  q0,  #4
     vdup.8      q0,  d0[0]
     b           pred16x16_dc_end
-.endfunc
+endfunc
 
 function x264_predict_16x16_dc_neon
     sub         r3, r0, #FDEC_STRIDE
@@ -616,7 +616,7 @@ pred16x16_dc_end:
     vst1.64     {d0-d1}, [r0,:128], r1
 .endr
     bx          lr
-.endfunc
+endfunc
 
 function x264_predict_16x16_h_neon
     sub         r1, r0, #1
@@ -630,7 +630,7 @@ function x264_predict_16x16_h_neon
     vst1.64     {d2-d3}, [r0,:128], ip
 .endr
     bx          lr
-.endfunc
+endfunc
 
 function x264_predict_16x16_v_neon
     sub         r0, r0, #FDEC_STRIDE
@@ -640,7 +640,7 @@ function x264_predict_16x16_v_neon
     vst1.64     {d0-d1}, [r0,:128], ip
 .endr
     bx          lr
-.endfunc
+endfunc
 
 function x264_predict_16x16_p_neon
     sub         r3,  r0,  #FDEC_STRIDE
@@ -697,4 +697,4 @@ function x264_predict_16x16_p_neon
     subs        r3,  r3,  #1
     bne         1b
     bx          lr
-.endfunc
+endfunc
