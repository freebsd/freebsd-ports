--- common/arm/quant-a.S.orig	2014-08-27 20:45:08 UTC
+++ common/arm/quant-a.S
@@ -80,7 +80,7 @@ function x264_quant_2x2_dc_neon
     vsub.s16    d3,  d3,  d0
     vst1.64     {d3}, [r0,:64]
     QUANT_END   d3
-.endfunc
+endfunc
 
 // quant_4x4_dc( int16_t dct[16], int mf, int bias )
 function x264_quant_4x4_dc_neon
@@ -92,7 +92,7 @@ function x264_quant_4x4_dc_neon
     QUANT_TWO   q0,  q0,  d4,  d5,  d4,  d5,  q0
     vorr        d0,  d0,  d1
     QUANT_END   d0
-.endfunc
+endfunc
 
 // quant_4x4( int16_t dct[16], uint16_t mf[16], uint16_t bias[16] )
 function x264_quant_4x4_neon
@@ -104,7 +104,7 @@ function x264_quant_4x4_neon
     QUANT_TWO   q0,  q1,  d4,  d5,  d6,  d7, q0
     vorr        d0,  d0,  d1
     QUANT_END   d0
-.endfunc
+endfunc
 
 // quant_4x4x4( int16_t dct[4][16], uint16_t mf[16], uint16_t bias[16] )
 function x264_quant_4x4x4_neon
@@ -145,7 +145,7 @@ function x264_quant_4x4x4_neon
     orrne       r0,  #8
     vpop        {d8-d15}
     bx          lr
-.endfunc
+endfunc
 
 // quant_8x8( int16_t dct[64], uint16_t mf[64], uint16_t bias[64] )
 function x264_quant_8x8_neon
@@ -165,7 +165,7 @@ function x264_quant_8x8_neon
 .endr
     vorr        d0,  d0,  d1
     QUANT_END   d0
-.endfunc
+endfunc
 
 .macro DEQUANT_START mf_size offset dc=no
     mov         r3,  #0x2b
@@ -257,7 +257,7 @@ dequant_\size\()_rshift_loop:
     bgt         dequant_\size\()_rshift_loop
 .endif
     bx          lr
-.endfunc
+endfunc
 .endm
 
 DEQUANT 4x4, 4
@@ -307,7 +307,7 @@ dequant_4x4_dc_rshift:
     vmovn.s32   d3,  q13
     vst1.16     {d0-d3},   [r0,:128]
     bx          lr
-.endfunc
+endfunc
 
 
 // int coeff_last( int16_t *l )
@@ -319,7 +319,7 @@ function x264_coeff_last4_arm
     lsrs        r2,  r2,  #16
     addne       r0,  r0,  #1
     bx          lr
-.endfunc
+endfunc
 
 function x264_coeff_last8_arm
     ldrd        r2,  r3,  [r0, #8]
@@ -333,7 +333,7 @@ function x264_coeff_last8_arm
     lsrs        r2,  r2,  #16
     addne       r0,  r0,  #1
     bx          lr
-.endfunc
+endfunc
 
 .macro COEFF_LAST_1x size
 function x264_coeff_last\size\()_neon
@@ -358,7 +358,7 @@ function x264_coeff_last\size\()_neon
     subslt      r0,  r3,  r0,  lsr #2
     movlt       r0,  #0
     bx          lr
-.endfunc
+endfunc
 .endm
 
 COEFF_LAST_1x 15
@@ -407,4 +407,4 @@ function x264_coeff_last64_neon
     subslt      r0,  ip,  r0
     movlt       r0,  #0
     bx          lr
-.endfunc
+endfunc
