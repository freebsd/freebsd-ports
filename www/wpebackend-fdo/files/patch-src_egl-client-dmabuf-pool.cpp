--- src/egl-client-dmabuf-pool.cpp.orig	2021-10-18 22:13:13 UTC
+++ src/egl-client-dmabuf-pool.cpp
@@ -182,10 +182,10 @@ void TargetDmabufPool::frameWillRender()
                 uint32_t modifier_lo = bufferData.modifiers[0] & 0xFFFFFFFF;
                 std::array<EGLAttrib, 10> planeAttributes = {
                         EGL_DMA_BUF_PLANE0_FD_EXT, bufferData.fds[0],
-                        EGL_DMA_BUF_PLANE0_PITCH_EXT, bufferData.strides[0],
-                        EGL_DMA_BUF_PLANE0_OFFSET_EXT, bufferData.offsets[0],
-                        EGL_DMA_BUF_PLANE0_MODIFIER_HI_EXT, modifier_hi,
-                        EGL_DMA_BUF_PLANE0_MODIFIER_LO_EXT, modifier_lo,
+                        EGL_DMA_BUF_PLANE0_PITCH_EXT, static_cast<int>(bufferData.strides[0]),
+                        EGL_DMA_BUF_PLANE0_OFFSET_EXT, static_cast<int>(bufferData.offsets[0]),
+                        EGL_DMA_BUF_PLANE0_MODIFIER_HI_EXT, static_cast<int>(modifier_hi),
+                        EGL_DMA_BUF_PLANE0_MODIFIER_LO_EXT, static_cast<int>(modifier_lo),
                     };
 
                 std::copy(planeAttributes.begin(), planeAttributes.end(),
@@ -198,10 +198,10 @@ void TargetDmabufPool::frameWillRender()
                 uint32_t modifier_lo = bufferData.modifiers[1] & 0xFFFFFFFF;
                 std::array<EGLAttrib, 10> planeAttributes = {
                         EGL_DMA_BUF_PLANE1_FD_EXT, bufferData.fds[1],
-                        EGL_DMA_BUF_PLANE1_PITCH_EXT, bufferData.strides[1],
-                        EGL_DMA_BUF_PLANE1_OFFSET_EXT, bufferData.offsets[1],
-                        EGL_DMA_BUF_PLANE1_MODIFIER_HI_EXT, modifier_hi,
-                        EGL_DMA_BUF_PLANE1_MODIFIER_LO_EXT, modifier_lo,
+                        EGL_DMA_BUF_PLANE1_PITCH_EXT, static_cast<int>(bufferData.strides[1]),
+                        EGL_DMA_BUF_PLANE1_OFFSET_EXT, static_cast<int>(bufferData.offsets[1]),
+                        EGL_DMA_BUF_PLANE1_MODIFIER_HI_EXT, static_cast<int>(modifier_hi),
+                        EGL_DMA_BUF_PLANE1_MODIFIER_LO_EXT, static_cast<int>(modifier_lo),
                     };
 
                 std::copy(planeAttributes.begin(), planeAttributes.end(),
@@ -214,10 +214,10 @@ void TargetDmabufPool::frameWillRender()
                 uint32_t modifier_lo = bufferData.modifiers[2] & 0xFFFFFFFF;
                 std::array<EGLAttrib, 10> planeAttributes = {
                         EGL_DMA_BUF_PLANE2_FD_EXT, bufferData.fds[2],
-                        EGL_DMA_BUF_PLANE2_PITCH_EXT, bufferData.strides[2],
-                        EGL_DMA_BUF_PLANE2_OFFSET_EXT, bufferData.offsets[2],
-                        EGL_DMA_BUF_PLANE2_MODIFIER_HI_EXT, modifier_hi,
-                        EGL_DMA_BUF_PLANE2_MODIFIER_LO_EXT, modifier_lo,
+                        EGL_DMA_BUF_PLANE2_PITCH_EXT, static_cast<int>(bufferData.strides[2]),
+                        EGL_DMA_BUF_PLANE2_OFFSET_EXT, static_cast<int>(bufferData.offsets[2]),
+                        EGL_DMA_BUF_PLANE2_MODIFIER_HI_EXT, static_cast<int>(modifier_hi),
+                        EGL_DMA_BUF_PLANE2_MODIFIER_LO_EXT, static_cast<int>(modifier_lo),
                     };
 
                 std::copy(planeAttributes.begin(), planeAttributes.end(),
@@ -230,10 +230,10 @@ void TargetDmabufPool::frameWillRender()
                 uint32_t modifier_lo = bufferData.modifiers[3] & 0xFFFFFFFF;
                 std::array<EGLAttrib, 10> planeAttributes = {
                         EGL_DMA_BUF_PLANE3_FD_EXT, bufferData.fds[3],
-                        EGL_DMA_BUF_PLANE3_PITCH_EXT, bufferData.strides[3],
-                        EGL_DMA_BUF_PLANE3_OFFSET_EXT, bufferData.offsets[3],
-                        EGL_DMA_BUF_PLANE3_MODIFIER_HI_EXT, modifier_hi,
-                        EGL_DMA_BUF_PLANE3_MODIFIER_LO_EXT, modifier_lo,
+                        EGL_DMA_BUF_PLANE3_PITCH_EXT, static_cast<int>(bufferData.strides[3]),
+                        EGL_DMA_BUF_PLANE3_OFFSET_EXT, static_cast<int>(bufferData.offsets[3]),
+                        EGL_DMA_BUF_PLANE3_MODIFIER_HI_EXT, static_cast<int>(modifier_hi),
+                        EGL_DMA_BUF_PLANE3_MODIFIER_LO_EXT, static_cast<int>(modifier_lo),
                     };
 
                 std::copy(planeAttributes.begin(), planeAttributes.end(),
