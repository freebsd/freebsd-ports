--- third_party/angle/src/libANGLE/renderer/gl/renderergl_utils.cpp.orig	2017-08-02 15:06:28.319994000 +0200
+++ third_party/angle/src/libANGLE/renderer/gl/renderergl_utils.cpp	2017-08-02 15:06:50.485321000 +0200
@@ -952,7 +952,7 @@
     workarounds->doesSRGBClearsOnLinearFramebufferAttachments =
         functions->standard == STANDARD_GL_DESKTOP && (IsIntel(vendor) || IsAMD(vendor));
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     workarounds->emulateMaxVertexAttribStride =
         functions->standard == STANDARD_GL_DESKTOP && IsAMD(vendor);
     workarounds->useUnusedBlocksWithStandardOrSharedLayout = IsAMD(vendor);
