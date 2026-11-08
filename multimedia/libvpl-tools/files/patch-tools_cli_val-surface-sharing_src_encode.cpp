--- tools/cli/val-surface-sharing/src/encode.cpp.orig	2026-06-25 23:06:43 UTC
+++ tools/cli/val-surface-sharing/src/encode.cpp
@@ -238,7 +238,7 @@ mfxStatus CEncodeTest::ProcessStreamEncode() {

     std::vector<mfxU8> bsInput(surfaceSize, 0);

-#ifdef __linux__
+#ifdef __unix__
     VASurfaceID vaSurfaceID;
 #endif

@@ -368,7 +368,7 @@ mfxStatus CEncodeTest::ProcessStreamEncode() {
                                               &m_fileInfo.bitstream,
                                               &syncp);

-#ifdef __linux__
+#ifdef __unix__
         if (m_pOpts->surfaceMode != SURFACE_MODE_SHARED)
 #endif
         {
@@ -388,7 +388,7 @@ mfxStatus CEncodeTest::ProcessStreamEncode() {
                             WriteEncodedStream(m_fileInfo.bitstream, m_fileInfo.outfile);
                             frameNum++;
                         }
-#ifdef __linux__
+#ifdef __unix__
                         if (sts != MFX_WRN_IN_EXECUTION) {
                             if (m_pOpts->surfaceMode == SURFACE_MODE_SHARED)
                                 ReleaseFreeSurfaces();
@@ -447,7 +447,7 @@ mfxStatus CEncodeTest::Run() {
     return MFX_ERR_NONE;
 }

-#ifdef __linux__
+#ifdef __unix__
 void CEncodeTest::ReleaseFreeSurfaces() {
     std::list<ImportedVASurfaceWrapper> surfaces_to_delete;

