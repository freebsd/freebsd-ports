--- modules/codec/aom.c.orig	2018-12-19 00:05:20 UTC
+++ modules/codec/aom.c
@@ -98,7 +98,6 @@ uint8_t          i_needs_hack;
 { VLC_CODEC_I444, AOM_IMG_FMT_I444, 8, 0 },
 
 { VLC_CODEC_YV12, AOM_IMG_FMT_YV12, 8, 0 },
-{ VLC_CODEC_YUVA, AOM_IMG_FMT_444A, 8, 0 },
 
 { VLC_CODEC_GBR_PLANAR, AOM_IMG_FMT_I444, 8, 1 },
 { VLC_CODEC_GBR_PLANAR_10L, AOM_IMG_FMT_I44416, 10, 1 },
