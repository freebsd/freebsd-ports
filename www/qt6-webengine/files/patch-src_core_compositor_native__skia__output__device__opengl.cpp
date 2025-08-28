--- src/core/compositor/native_skia_output_device_opengl.cpp.orig	2025-08-18 00:53:11 UTC
+++ src/core/compositor/native_skia_output_device_opengl.cpp
@@ -248,7 +248,7 @@ QSGTexture *NativeSkiaOutputDeviceOpenGL::texture(QQui
                 EGL_LINUX_DRM_FOURCC_EXT, drmFormat,
                 EGL_DMA_BUF_PLANE0_FD_EXT, scopedFd.get(),
                 EGL_DMA_BUF_PLANE0_OFFSET_EXT, static_cast<EGLAttrib>(nativePixmap->GetDmaBufOffset(0)),
-                EGL_DMA_BUF_PLANE0_PITCH_EXT, nativePixmap->GetDmaBufPitch(0),
+                EGL_DMA_BUF_PLANE0_PITCH_EXT, static_cast<EGLAttrib>(nativePixmap->GetDmaBufPitch(0)),
                 EGL_DMA_BUF_PLANE0_MODIFIER_LO_EXT, static_cast<EGLAttrib>(modifier & 0xffffffff),
                 EGL_DMA_BUF_PLANE0_MODIFIER_HI_EXT, static_cast<EGLAttrib>(modifier >> 32),
                 EGL_NONE
