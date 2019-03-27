--- src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/gl/renderergl_utils.cpp.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/gl/renderergl_utils.cpp
@@ -1127,7 +1127,7 @@ void GenerateWorkarounds(const FunctionsGL *functions,
     workarounds->doesSRGBClearsOnLinearFramebufferAttachments =
         functions->standard == STANDARD_GL_DESKTOP && (IsIntel(vendor) || IsAMD(vendor));
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     workarounds->emulateMaxVertexAttribStride =
         functions->standard == STANDARD_GL_DESKTOP && IsAMD(vendor);
     workarounds->useUnusedBlocksWithStandardOrSharedLayout = IsAMD(vendor);
