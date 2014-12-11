--- gst-libs/ext/libav/libavcodec/arm/ac3dsp_armv6.S.orig	2014-11-28 14:36:09 UTC
+++ gst-libs/ext/libav/libavcodec/arm/ac3dsp_armv6.S
@@ -37,14 +37,16 @@ function ff_ac3_bit_alloc_calc_bap_armv6
         ldrb            r10, [r4], #1
 1:
         ldrsh           r9,  [r0], #2                   @ mask[band]
-        movw            r8,  #0x1fe0
+        mov             r8,  #0xff0
         sub             r9,  r9,  r12                   @   - snr_offset
         mov             r11, r10
         ldrb            r10, [r4], #1                   @ band_start_tab[band++]
         subs            r9,  r9,  r5                    @   - floor
+        it              lt
         movlt           r9,  #0
         cmp             r10, r3                         @   - end
-        and             r9,  r9,  r8                    @   & 0x1fe0
+        and             r9,  r9,  r8, lsl #1            @   & 0x1fe0
+        ite             gt
         subgt           r8,  r3,  r11
         suble           r8,  r10, r11
         add             r9,  r9,  r5                    @   + floor => m
