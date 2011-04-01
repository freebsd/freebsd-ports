--- ffmpeg/libavcodec/x86/snowdsp_mmx.c.orig	2011-03-12 15:13:39.000000000 +0100
+++ ffmpeg/libavcodec/x86/snowdsp_mmx.c	2011-03-25 13:12:53.087099520 +0100
@@ -675,14 +675,14 @@
 
 #define snow_inner_add_yblock_sse2_end_8\
              "sal $1, %%"REG_c"              \n\t"\
-             "add $"PTR_SIZE"*2, %1          \n\t"\
+             "addb $"PTR_SIZE"*2, %1          \n\t"\
              snow_inner_add_yblock_sse2_end_common1\
              "sar $1, %%"REG_c"              \n\t"\
              "sub $2, %2                     \n\t"\
              snow_inner_add_yblock_sse2_end_common2
 
 #define snow_inner_add_yblock_sse2_end_16\
-             "add $"PTR_SIZE"*1, %1          \n\t"\
+             "addw $"PTR_SIZE"*1, %1          \n\t"\
              snow_inner_add_yblock_sse2_end_common1\
              "dec %2                         \n\t"\
              snow_inner_add_yblock_sse2_end_common2
