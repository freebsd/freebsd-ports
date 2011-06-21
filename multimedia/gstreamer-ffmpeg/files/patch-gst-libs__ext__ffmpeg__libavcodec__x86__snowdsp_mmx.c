--- gst-libs/ext/ffmpeg/libavcodec/x86/snowdsp_mmx.c.orig	2011-06-21 15:24:51.000000000 +0200
+++ gst-libs/ext/ffmpeg/libavcodec/x86/snowdsp_mmx.c	2011-06-21 15:26:51.000000000 +0200
@@ -805,13 +805,19 @@ snow_inner_add_yblock_sse2_end_16
              "packuswb %%mm5, %%mm1          \n\t"\
              "movq %%mm1, "write_offset"(%%"REG_d") \n\t"
 
+#if ARCH_X86_64
+#define OPSIZE "q"
+#else
+#define OPSIZE "l"
+#endif
+
 #define snow_inner_add_yblock_mmx_end(s_step)\
              "add $"s_step", %%"REG_S"             \n\t"\
              "add %%"REG_c", "PTR_SIZE"*3(%%"REG_a");\n\t"\
              "add %%"REG_c", "PTR_SIZE"*2(%%"REG_a");\n\t"\
              "add %%"REG_c", "PTR_SIZE"*1(%%"REG_a");\n\t"\
              "add %%"REG_c", (%%"REG_a")     \n\t"\
-             "add $"PTR_SIZE"*1, %1          \n\t"\
+             "add"OPSIZE" $"PTR_SIZE"*1, %1          \n\t"\
              "add %%"REG_c", %0              \n\t"\
              "dec %2                         \n\t"\
              "jnz 1b                         \n\t"\
