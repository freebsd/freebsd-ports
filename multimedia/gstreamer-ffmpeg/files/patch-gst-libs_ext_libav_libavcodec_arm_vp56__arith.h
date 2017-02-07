--- gst-libs/ext/libav/libavcodec/arm/vp56_arith.h.orig	2017-01-23 16:31:45 UTC
+++ gst-libs/ext/libav/libavcodec/arm/vp56_arith.h
@@ -33,7 +33,7 @@ static inline int vp56_rac_get_prob_armv
 
     __asm__ ("adds    %3,  %3,  %0           \n"
              "cmpcs   %7,  %4                \n"
-             "ldrcsh  %2,  [%4], #2          \n"
+             "ldrhcs  %2,  [%4], #2          \n"
              "rsb     %0,  %6,  #256         \n"
              "smlabb  %0,  %5,  %6,  %0      \n"
              "rev16cs %2,  %2                \n"
@@ -65,7 +65,7 @@ static inline int vp56_rac_get_prob_bran
 
     __asm__ ("adds    %3,  %3,  %0           \n"
              "cmpcs   %7,  %4                \n"
-             "ldrcsh  %2,  [%4], #2          \n"
+             "ldrhcs  %2,  [%4], #2          \n"
              "rsb     %0,  %6,  #256         \n"
              "smlabb  %0,  %5,  %6,  %0      \n"
              "rev16cs %2,  %2                \n"
