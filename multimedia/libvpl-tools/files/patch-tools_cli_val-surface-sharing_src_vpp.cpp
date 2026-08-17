--- tools/cli/val-surface-sharing/src/vpp.cpp.orig	2026-06-25 23:06:43 UTC
+++ tools/cli/val-surface-sharing/src/vpp.cpp
@@ -251,7 +251,7 @@ mfxStatus CVPPTest::ProcessStreamVPP() {

     std::vector<mfxU8> bsInput(surfaceSize, 0);

-#ifdef __linux__
+#ifdef __unix__
     VASurfaceID vaSurfaceID;
 #endif

@@ -479,7 +479,7 @@ mfxStatus CVPPTest::ProcessStreamVPP() {
                                    "Could not release vpp output surface",
                                    sts);

-#ifdef __linux__
+#ifdef __unix__
                             if (!m_pOpts->bNoSSA && !isDraining &&
                                 m_pOpts->surfaceComponent != MFX_SURFACE_COMPONENT_VPP_OUTPUT) {
                                 VAStatus vaSts =
