--- tools/cli/val-surface-sharing/src/encode.h.orig	2026-06-25 23:06:43 UTC
+++ tools/cli/val-surface-sharing/src/encode.h
@@ -47,7 +47,7 @@ class CEncodeTest : public CTest { (private)
     mfxStatus CreateVPLSession();
     mfxStatus ProcessStreamEncode();

-#ifdef __linux__
+#ifdef __unix__

     struct ImportedVASurfaceWrapper {
         mfxFrameSurface1 *m_imported_mfx_surface;
