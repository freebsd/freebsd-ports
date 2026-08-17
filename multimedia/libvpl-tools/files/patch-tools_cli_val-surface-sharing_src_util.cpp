--- tools/cli/val-surface-sharing/src/util.cpp.orig	2026-07-23 01:58:41 UTC
+++ tools/cli/val-surface-sharing/src/util.cpp
@@ -445,7 +445,7 @@ mfxStatus GetAdaptersInfo(Options *opts, bool bPrint)
         if (dev->Version.Version >= MFX_STRUCT_VERSION(1, 1)) {
             mfxMediaAdapterType eMA = (mfxMediaAdapterType)dev->MediaAdapterType;
             if (eMA != MFX_MEDIA_UNKNOWN) {
-#ifdef __linux__
+#ifdef __unix__
                 mfxExtendedDeviceId *idescDevice = nullptr;
                 sts                              = MFXEnumImplementations(loader,
                                              i,
