--- libmpcodecs/vf_scale.h.orig	2016-11-30 00:01:44 UTC
+++ libmpcodecs/vf_scale.h
@@ -19,7 +19,6 @@
 #ifndef MPLAYER_VF_SCALE_H
 #define MPLAYER_VF_SCALE_H

-int get_sws_cpuflags(void);
 struct SwsContext *sws_getContextFromCmdLine(int srcW, int srcH, int srcFormat, int dstW, int dstH, int dstFormat);
 struct SwsContext *sws_getContextFromCmdLine_hq(int srcW, int srcH, int srcFormat, int dstW, int dstH, int dstFormat);

