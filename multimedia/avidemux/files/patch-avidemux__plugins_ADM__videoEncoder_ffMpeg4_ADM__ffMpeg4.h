--- avidemux_plugins/ADM_videoEncoder/ffMpeg4/ADM_ffMpeg4.h.orig	2016-01-29 08:47:25 UTC
+++ avidemux_plugins/ADM_videoEncoder/ffMpeg4/ADM_ffMpeg4.h
@@ -43,9 +43,9 @@
 		2,				/* max_b_frames */ \
 		0,				/* mpeg_quant */ \
 		1,				/* is_luma_elim_threshold */ \
-		-2,				/* luma_elim_threshold */ \
+		0,				/* luma_elim_threshold */ \
 		1,				/* is_chroma_elim_threshold */ \
-		-5,				/* chroma_elim_threshold */ \
+		0,				/* chroma_elim_threshold */ \
 		0.05,				/*lumi_masking */ \
 		1,				/* is lumi */ \
 		0.01,				/*dark_masking */ \
