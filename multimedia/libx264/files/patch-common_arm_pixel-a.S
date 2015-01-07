--- common/arm/pixel-a.S.orig	2014-08-27 20:45:08 UTC
+++ common/arm/pixel-a.S
@@ -29,10 +29,12 @@
 .section .rodata
 .align 4
 
-.rept 16 .byte 0xff
+.rept 16
+        .byte 0xff
 .endr
 mask_ff:
-.rept 16 .byte 0
+.rept 16
+        .byte 0
 .endr
 
 mask_ac4:
@@ -60,7 +62,7 @@ function x264_pixel_sad_4x\h\()_armv6
 .endr
     usada8      r0, r6, lr, ip
     pop         {r4-r6,pc}
-.endfunc
+endfunc
 .endm
 
 SAD4_ARMV6 4
@@ -137,7 +139,7 @@ function x264_pixel_sad\name\()_\w\()x\h
     vpaddl.u16  d0,  d0
     vmov.u32    r0,  d0[0]
     bx          lr
-.endfunc
+endfunc
 .endm
 
 SAD_FUNC  4,  4
@@ -222,7 +224,7 @@ function x264_pixel_sad_aligned_\w\()x\h
     vpaddl.u16  d0,  d0
     vmov.u32    r0,  d0[0]
     bx          lr
-.endfunc
+endfunc
 .endm
 
 SAD_FUNC_DUAL  8,  4
@@ -368,7 +370,7 @@ function x264_pixel_sad_x\x\()_\w\()x\h\
     vst1.32     {d0-d1}, [r7]
 .endif
     pop         {r6-r7,pc}
-.endfunc
+endfunc
 .endm
 
 SAD_X_FUNC  3, 4,  4
@@ -477,7 +479,7 @@ function x264_pixel_ssd_\w\()x\h\()_neon
     vpadd.s32   d0, d0, d0
     vmov.32     r0, d0[0]
     bx          lr
-.endfunc
+endfunc
 .endm
 
 SSD_FUNC   4, 4
@@ -517,7 +519,7 @@ function x264_pixel_var_8x8_neon
     vld1.64         {d26}, [r0,:64], r1
     VAR_SQR_SUM     q2,  q10,  q15, d26
     b               x264_var_end
-.endfunc
+endfunc
 
 function x264_pixel_var_8x16_neon
     vld1.64         {d16}, [r0,:64], r1
@@ -549,7 +551,7 @@ function x264_pixel_var_8x16_neon
 2:
     VAR_SQR_SUM     q2,  q13,  q15, d22
     b               x264_var_end
-.endfunc
+endfunc
 
 function x264_pixel_var_16x16_neon
     vld1.64         {d16-d17}, [r0,:128], r1
@@ -573,7 +575,7 @@ var16_loop:
     VAR_SQR_SUM     q1,  q12,  q14, d18
     VAR_SQR_SUM     q2,  q13,  q15, d19
     bgt             var16_loop
-.endfunc
+endfunc
 
 function x264_var_end, export=0
     vpaddl.u16      q8,  q14
@@ -588,7 +590,7 @@ function x264_var_end, export=0
 
     vmov            r0,  r1,  d0
     bx              lr
-.endfunc
+endfunc
 
 .macro DIFF_SUM diff da db lastdiff
     vld1.64         {\da}, [r0,:64], r1
@@ -633,7 +635,7 @@ function x264_pixel_var2_8x8_neon
     mul             r0,  r0,  r0
     sub             r0,  r1,  r0,  lsr #6
     bx              lr
-.endfunc
+endfunc
 
 function x264_pixel_var2_8x16_neon
     vld1.64         {d16}, [r0,:64], r1
@@ -677,7 +679,7 @@ function x264_pixel_var2_8x16_neon
     mul             r0,  r0,  r0
     sub             r0,  r1,  r0,  lsr #7
     bx              lr
-.endfunc
+endfunc
 
 .macro LOAD_DIFF_8x4 q0 q1 q2 q3
     vld1.32     {d1}, [r2], r3
@@ -714,7 +716,7 @@ function x264_pixel_satd_4x4_neon
     HORIZ_ADD   d0,  d0,  d1
     vmov.32     r0,  d0[0]
     bx          lr
-.endfunc
+endfunc
 
 function x264_pixel_satd_4x8_neon
     vld1.32     {d1[]},  [r2], r3
@@ -741,7 +743,7 @@ function x264_pixel_satd_4x8_neon
     vsubl.u8    q3,  d6,  d7
     SUMSUB_AB   q10, q11, q2,  q3
     b           x264_satd_4x8_8x4_end_neon
-.endfunc
+endfunc
 
 function x264_pixel_satd_8x4_neon
     vld1.64     {d1}, [r2], r3
@@ -758,7 +760,7 @@ function x264_pixel_satd_8x4_neon
     vld1.64     {d6}, [r0,:64], r1
     vsubl.u8    q3,  d6,  d7
     SUMSUB_AB   q10, q11, q2,  q3
-.endfunc
+endfunc
 
 function x264_satd_4x8_8x4_end_neon, export=0
     vadd.s16    q0,  q8,  q10
@@ -785,7 +787,7 @@ function x264_satd_4x8_8x4_end_neon, exp
     HORIZ_ADD   d0,  d0,  d1
     vmov.32     r0,  d0[0]
     bx          lr
-.endfunc
+endfunc
 
 function x264_pixel_satd_8x8_neon
     mov         ip,  lr
@@ -799,7 +801,7 @@ function x264_pixel_satd_8x8_neon
     mov         lr,  ip
     vmov.32     r0,  d0[0]
     bx          lr
-.endfunc
+endfunc
 
 function x264_pixel_satd_8x16_neon
     vpush       {d8-d11}
@@ -821,7 +823,7 @@ function x264_pixel_satd_8x16_neon
     mov         lr,  ip
     vmov.32     r0,  d0[0]
     bx          lr
-.endfunc
+endfunc
 
 function x264_satd_8x8_neon, export=0
     LOAD_DIFF_8x4 q8,  q9,  q10, q11
@@ -841,7 +843,7 @@ function x264_satd_8x8_neon, export=0
     SUMSUB_AB   q9,  q11, q1,  q3
     vld1.64     {d0}, [r0,:64], r1
     vsubl.u8    q15, d0,  d1
-.endfunc
+endfunc
 
 // one vertical hadamard pass and two horizontal
 function x264_satd_8x4v_8x8h_neon, export=0
@@ -870,7 +872,7 @@ function x264_satd_8x4v_8x8h_neon, expor
     vmax.s16    q14, q8,  q10
     vmax.s16    q15, q9,  q11
     bx          lr
-.endfunc
+endfunc
 
 function x264_pixel_satd_16x8_neon
     vpush       {d8-d11}
@@ -892,7 +894,7 @@ function x264_pixel_satd_16x8_neon
     mov         lr,  ip
     vmov.32     r0,  d0[0]
     bx          lr
-.endfunc
+endfunc
 
 function x264_pixel_satd_16x16_neon
     vpush       {d8-d11}
@@ -926,7 +928,7 @@ function x264_pixel_satd_16x16_neon
     mov         lr,  ip
     vmov.32     r0,  d0[0]
     bx          lr
-.endfunc
+endfunc
 
 function x264_satd_16x4_neon, export=0
     vld1.64     {d2-d3}, [r2], r3
@@ -950,7 +952,7 @@ function x264_satd_16x4_neon, export=0
     SUMSUB_AB   q2,  q3,  q10, q11
     SUMSUB_ABCD q8,  q10, q9,  q11, q0,  q2,  q1,  q3
     b           x264_satd_8x4v_8x8h_neon
-.endfunc
+endfunc
 
 
 function x264_pixel_sa8d_8x8_neon
@@ -963,7 +965,7 @@ function x264_pixel_sa8d_8x8_neon
     add             r0,  r0,  #1
     lsr             r0,  r0,  #1
     bx              lr
-.endfunc
+endfunc
 
 function x264_pixel_sa8d_16x16_neon
     vpush           {d8-d11}
@@ -995,7 +997,7 @@ function x264_pixel_sa8d_16x16_neon
     add             r0,  r0,  #1
     lsr             r0,  r0,  #1
     bx              lr
-.endfunc
+endfunc
 
 .macro HADAMARD4_V r1, r2, r3, r4, t1, t2, t3, t4
     SUMSUB_ABCD \t1, \t2, \t3, \t4, \r1, \r2, \r3, \r4
@@ -1058,7 +1060,7 @@ function x264_sa8d_8x8_neon, export=0
     vadd.i16        q8,  q8,  q9
     vadd.i16        q9,  q10, q11
     bx              lr
-.endfunc
+endfunc
 
 
 .macro HADAMARD_AC w h
@@ -1094,7 +1096,7 @@ function x264_pixel_hadamard_ac_\w\()x\h
     lsr             r0,  r0,  #1
     lsr             r1,  r1,  #2
     bx              lr
-.endfunc
+endfunc
 .endm
 
 HADAMARD_AC  8, 8
@@ -1189,7 +1191,7 @@ function x264_hadamard_ac_8x8_neon, expo
     vadd.s16        q2,  q2,  q14
     vpadal.u16      q5,  q2
     bx              lr
-.endfunc
+endfunc
 
 
 .macro SSIM_ITER n ssa s12 ssb lastssa lasts12 lastssb da db dnext
@@ -1243,7 +1245,7 @@ function x264_pixel_ssim_4x4x2_core_neon
 
     vst4.32     {d0-d3}, [ip]
     bx          lr
-.endfunc
+endfunc
 
 // FIXME: see about doing 16x16 -> 32 bit multiplies for s1/s2
 function x264_pixel_ssim_end4_neon
@@ -1314,4 +1316,4 @@ ssim_skip:
     vpadd.f32   d0,  d0,  d0
     vmov.32     r0,  d0[0]
     bx          lr
-.endfunc
+endfunc
