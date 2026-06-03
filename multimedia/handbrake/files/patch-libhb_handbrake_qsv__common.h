--- libhb/handbrake/qsv_common.h.orig	2025-08-08 16:41:24 UTC
+++ libhb/handbrake/qsv_common.h
@@ -260,8 +260,13 @@ typedef struct
 {
     mfxExtCodingOption2   codingOption2;
     hb_triplet_t*         hyperEncodeParam;
+#if (MFX_VERSION >= 2012)
     mfxExtAV1ScreenContentTools av1ScreenContentToolsParam;
-
+#endif
+    mfxExtChromaLocInfo   chromaLocInfo;
+    mfxExtMasteringDisplayColourVolume masteringDisplayColourVolume;
+    mfxExtContentLightLevelInfo        contentLightLevelInfo;
+    mfxExtAV1BitstreamParam av1BitstreamParam;
     struct
     {
         int b_pyramid;
