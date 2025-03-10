--- libhb/handbrake/qsv_common.h.orig	2024-12-01 15:28:40 UTC
+++ libhb/handbrake/qsv_common.h
@@ -171,7 +171,9 @@ typedef struct
     mfxExtCodingOption2   codingOption2;
     mfxExtVideoSignalInfo videoSignalInfo;
     mfxExtHyperModeParam hyperEncodeParam;
+#if (MFX_VERSION >= 2012)
     mfxExtAV1ScreenContentTools av1ScreenContentToolsParam;
+#endif
     mfxExtChromaLocInfo   chromaLocInfo;
     mfxExtMasteringDisplayColourVolume masteringDisplayColourVolume;
     mfxExtContentLightLevelInfo        contentLightLevelInfo;
