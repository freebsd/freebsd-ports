--- common/arm/mc-a.S.orig	2014-08-27 20:45:08 UTC
+++ common/arm/mc-a.S
@@ -50,7 +50,7 @@ function x264_prefetch_ref_arm
     pld         [r3, r1, lsl #1]
     pld         [r3, r2]
     bx          lr
-.endfunc
+endfunc
 
 // void prefetch_fenc( uint8_t *pix_y,  intptr_t stride_y,
 //                     uint8_t *pix_uv, intptr_t stride_uv, int mb_x )
@@ -76,7 +76,7 @@ function x264_prefetch_fenc_arm
     pld         [ip]
     pld         [ip, r3]
     pop         {pc}
-.endfunc
+endfunc
 
 
 // void *x264_memcpy_aligned( void *dst, const void *src, size_t n )
@@ -85,7 +85,7 @@ function x264_memcpy_aligned_neon
     movrel      ip,  memcpy_table
     and         r3,  r3,  #0xc
     ldr         pc,  [ip, r3]
-.endfunc
+endfunc
 
 .macro MEMCPY_ALIGNED srcalign dstalign
 function memcpy_aligned_\dstalign\()_\srcalign\()_neon, export=0
@@ -127,7 +127,7 @@ function memcpy_aligned_\dstalign\()_\sr
     vst1.64     {d0}, [r3,:64]!
 .endif
     bx          lr
-.endfunc
+endfunc
 .endm
 
 MEMCPY_ALIGNED 16, 16
@@ -156,7 +156,7 @@ memzero_loop:
 .endr
     bgt         memzero_loop
     bx          lr
-.endfunc
+endfunc
 
 
 // void pixel_avg( uint8_t *dst,  intptr_t dst_stride,
@@ -175,7 +175,7 @@ function x264_pixel_avg_\w\()x\h\()_neon
     cmp         ip,  #0
     bge         x264_pixel_avg_weight_w\w\()_add_add_neon
     b           x264_pixel_avg_weight_w\w\()_sub_add_neon     // weight < 0
-.endfunc
+endfunc
 .endm
 
 AVGH  4, 2
@@ -253,7 +253,7 @@ function x264_pixel_avg_weight_w4_\ext\(
     vst1.32         {d1[0]}, [r0,:32], r1
     bgt             1b
     pop             {r4-r6,pc}
-.endfunc
+endfunc
 
 function x264_pixel_avg_weight_w8_\ext\()_neon, export=0
     load_weights_\ext
@@ -277,7 +277,7 @@ function x264_pixel_avg_weight_w8_\ext\(
     vst1.64         {d3}, [r0,:64], r1
     bgt             1b
     pop             {r4-r6,pc}
-.endfunc
+endfunc
 
 function x264_pixel_avg_weight_w16_\ext\()_neon, export=0
     load_weights_\ext
@@ -297,7 +297,7 @@ function x264_pixel_avg_weight_w16_\ext\
     vst1.64         {d2-d3}, [r0,:128], r1
     bgt             1b
     pop             {r4-r6,pc}
-.endfunc
+endfunc
 .endm
 
 AVG_WEIGHT add_add
@@ -316,7 +316,7 @@ function x264_pixel_avg_w4_neon, export=
     vst1.32     {d1[0]}, [r0,:32], r1
     bgt         x264_pixel_avg_w4_neon
     pop         {r4-r6,pc}
-.endfunc
+endfunc
 
 function x264_pixel_avg_w8_neon, export=0
     subs        lr,  lr,  #4
@@ -338,7 +338,7 @@ function x264_pixel_avg_w8_neon, export=
     vst1.64     {d3}, [r0,:64], r1
     bgt         x264_pixel_avg_w8_neon
     pop         {r4-r6,pc}
-.endfunc
+endfunc
 
 function x264_pixel_avg_w16_neon, export=0
     subs        lr,  lr,  #4
@@ -360,7 +360,7 @@ function x264_pixel_avg_w16_neon, export
     vst1.64     {d6-d7}, [r0,:128], r1
     bgt         x264_pixel_avg_w16_neon
     pop         {r4-r6,pc}
-.endfunc
+endfunc
 
 
 function x264_pixel_avg2_w4_neon
@@ -379,7 +379,7 @@ avg2_w4_loop:
     vst1.32     {d1[0]}, [r0,:32], r1
     bgt         avg2_w4_loop
     pop         {pc}
-.endfunc
+endfunc
 
 function x264_pixel_avg2_w8_neon
     ldr         ip,  [sp, #4]
@@ -397,7 +397,7 @@ avg2_w8_loop:
     vst1.64     {d1}, [r0,:64], r1
     bgt         avg2_w8_loop
     pop         {pc}
-.endfunc
+endfunc
 
 function x264_pixel_avg2_w16_neon
     ldr         ip,  [sp, #4]
@@ -415,7 +415,7 @@ avg2_w16_loop:
     vst1.64     {d4-d5}, [r0,:128], r1
     bgt         avg2_w16_loop
     pop         {pc}
-.endfunc
+endfunc
 
 function x264_pixel_avg2_w20_neon
     ldr         ip,  [sp, #4]
@@ -438,7 +438,7 @@ avg2_w20_loop:
     vst1.32     {d6[0]},  [r0,:32], r1
     bgt         avg2_w20_loop
     pop         {pc}
-.endfunc
+endfunc
 
 
 .macro weight_prologue type
@@ -499,7 +499,7 @@ weight20_loop:
     vst1.32     {d20[1]},  [r0,:32], r1
     bgt         weight20_loop
     pop         {r4-r5,pc}
-.endfunc
+endfunc
 
 function x264_mc_weight_w16_neon
     weight_prologue full
@@ -531,7 +531,7 @@ weight16_loop:
     vst1.8      {d18-d19}, [r0,:128], r1
     bgt         weight16_loop
     pop         {r4-r5,pc}
-.endfunc
+endfunc
 
 function x264_mc_weight_w8_neon
     weight_prologue full
@@ -553,7 +553,7 @@ weight8_loop:
     vst1.8      {d18}, [r0,:64], r1
     bgt         weight8_loop
     pop         {r4-r5,pc}
-.endfunc
+endfunc
 
 function x264_mc_weight_w4_neon
     weight_prologue full
@@ -572,7 +572,7 @@ weight4_loop:
     vst1.32     {d16[1]}, [r0,:32], r1
     bgt         weight4_loop
     pop         {r4-r5,pc}
-.endfunc
+endfunc
 
 function x264_mc_weight_w20_nodenom_neon
     weight_prologue nodenom
@@ -609,7 +609,7 @@ weight20_nodenom_loop:
     vst1.32     {d20[1]},  [r0,:32], r1
     bgt         weight20_nodenom_loop
     pop         {r4-r5,pc}
-.endfunc
+endfunc
 
 function x264_mc_weight_w16_nodenom_neon
     weight_prologue nodenom
@@ -637,7 +637,7 @@ weight16_nodenom_loop:
     vst1.8      {d18-d19}, [r0,:128], r1
     bgt         weight16_nodenom_loop
     pop         {r4-r5,pc}
-.endfunc
+endfunc
 
 function x264_mc_weight_w8_nodenom_neon
     weight_prologue nodenom
@@ -657,7 +657,7 @@ weight8_nodenom_loop:
     vst1.8      {d17}, [r0,:64], r1
     bgt         weight8_nodenom_loop
     pop         {r4-r5,pc}
-.endfunc
+endfunc
 
 function x264_mc_weight_w4_nodenom_neon
     weight_prologue nodenom
@@ -675,7 +675,7 @@ weight4_nodenom_loop:
     vst1.32     {d16[1]}, [r0,:32], r1
     bgt         weight4_nodenom_loop
     pop         {r4-r5,pc}
-.endfunc
+endfunc
 
 .macro weight_simple_prologue
     push        {lr}
@@ -699,7 +699,7 @@ weight20_\name\()_loop:
     vst1.8      {d19-d21}, [r0,:64], r1
     bgt         weight20_\name\()_loop
     pop         {pc}
-.endfunc
+endfunc
 
 function x264_mc_weight_w16_\name\()_neon
     weight_simple_prologue
@@ -713,7 +713,7 @@ weight16_\name\()_loop:
     vst1.8      {d18-d19}, [r0,:128], r1
     bgt         weight16_\name\()_loop
     pop         {pc}
-.endfunc
+endfunc
 
 function x264_mc_weight_w8_\name\()_neon
     weight_simple_prologue
@@ -726,7 +726,7 @@ weight8_\name\()_loop:
     vst1.8      {d17}, [r0,:64], r1
     bgt         weight8_\name\()_loop
     pop         {pc}
-.endfunc
+endfunc
 
 function x264_mc_weight_w4_\name\()_neon
     weight_simple_prologue
@@ -739,7 +739,7 @@ weight4_\name\()_loop:
     vst1.32     {d17[0]}, [r0,:32], r1
     bgt         weight4_\name\()_loop
     pop         {pc}
-.endfunc
+endfunc
 .endm
 
 weight_simple offsetadd, vqadd.u8
@@ -761,7 +761,7 @@ copy_w4_loop:
     vst1.32     {d3[0]}, [r0,:32], r1
     bgt         copy_w4_loop
     bx          lr
-.endfunc
+endfunc
 
 function x264_mc_copy_w8_neon
     ldr         ip,  [sp]
@@ -777,7 +777,7 @@ copy_w8_loop:
     vst1.32     {d3}, [r0,:64], r1
     bgt         copy_w8_loop
     bx          lr
-.endfunc
+endfunc
 
 function x264_mc_copy_w16_neon
     ldr         ip,  [sp]
@@ -793,7 +793,7 @@ copy_w16_loop:
     vst1.32     {d6-d7}, [r0,:128], r1
     bgt         copy_w16_loop
     bx          lr
-.endfunc
+endfunc
 
 function x264_mc_copy_w16_aligned_neon
     ldr         ip,  [sp]
@@ -809,7 +809,7 @@ copy_w16_aligned_loop:
     vst1.32     {d6-d7}, [r0,:128], r1
     bgt         copy_w16_aligned_loop
     bx          lr
-.endfunc
+endfunc
 
 
 // void x264_mc_chroma_neon( uint8_t *dst, intptr_t i_dst_stride,
@@ -1159,7 +1159,7 @@ mc_chroma_w8:
     vpop            {d8-d11}
     pop             {r4-r8, pc}
 
-.endfunc
+endfunc
 
 
 // hpel_filter_v( uint8_t *dst, uint8_t *src, int16_t *buf, intptr_t stride, int width )
@@ -1200,7 +1200,7 @@ filter_v_loop:
     vst1.64         {d0-d1},   [r0,:128]!
     bgt             filter_v_loop
     pop             {pc}
-.endfunc
+endfunc
 
 // hpel_filter_c( uint8_t *dst, int16_t *buf, int width );
 function x264_hpel_filter_c_neon
@@ -1285,7 +1285,7 @@ filter_c_loop:
     vst1.64         {d30-d31}, [r0,:128]!
     bgt             filter_c_loop
     bx              lr
-.endfunc
+endfunc
 
 // hpel_filter_h( uint8_t *dst, uint8_t *src, int width );
 function x264_hpel_filter_h_neon
@@ -1372,7 +1372,7 @@ filter_h_loop:
     vst1.64         {d6-d7}, [r0,:128]!
     bgt             filter_h_loop
     bx              lr
-.endfunc
+endfunc
 
 
 // frame_init_lowres_core( uint8_t *src0, uint8_t *dst0, uint8_t *dsth, uint8_t *dstv,
@@ -1464,7 +1464,7 @@ lowres_xloop_end:
 
     vpop            {d8-d15}
     pop             {r4-r10,pc}
-.endfunc
+endfunc
 
 function x264_load_deinterleave_chroma_fdec_neon
     mov             ip,  #FDEC_STRIDE/2
@@ -1477,7 +1477,7 @@ function x264_load_deinterleave_chroma_f
     bgt             1b
 
     bx              lr
-.endfunc
+endfunc
 
 function x264_load_deinterleave_chroma_fenc_neon
     mov             ip,  #FENC_STRIDE/2
@@ -1490,7 +1490,7 @@ function x264_load_deinterleave_chroma_f
     bgt             1b
 
     bx              lr
-.endfunc
+endfunc
 
 function x264_plane_copy_deinterleave_neon
     push            {r4-r7, lr}
@@ -1516,7 +1516,7 @@ block:
     bgt             block
 
     pop             {r4-r7, pc}
-.endfunc
+endfunc
 
 function x264_plane_copy_deinterleave_rgb_neon
     push            {r4-r8, r10, r11, lr}
@@ -1568,7 +1568,7 @@ block4:
     bgt             block4
 
     pop             {r4-r8, r10, r11, pc}
-.endfunc
+endfunc
 
 function x264_plane_copy_interleave_neon
     push            {r4-r7, lr}
@@ -1595,7 +1595,7 @@ blocki:
     bgt             blocki
 
     pop             {r4-r7, pc}
-.endfunc
+endfunc
 
 function x264_store_interleave_chroma_neon
     push            {lr}
@@ -1609,4 +1609,4 @@ function x264_store_interleave_chroma_ne
     bgt             1b
 
     pop             {pc}
-.endfunc
+endfunc
