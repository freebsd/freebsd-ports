--- modules/codec/aom.c.orig	2018-07-24 15:13:43 UTC
+++ modules/codec/aom.c
@@ -96,7 +96,6 @@ static const struct
     { VLC_CODEC_I444, AOM_IMG_FMT_I444, 8, 0 },
 
     { VLC_CODEC_YV12, AOM_IMG_FMT_YV12, 8, 0 },
-    { VLC_CODEC_YUVA, AOM_IMG_FMT_444A, 8, 0 },
 
     { VLC_CODEC_GBR_PLANAR, AOM_IMG_FMT_I444, 8, 1 },
     { VLC_CODEC_GBR_PLANAR_10L, AOM_IMG_FMT_I44416, 10, 1 },
