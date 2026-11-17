--- device/vr/openxr/openxr_render_loop.h.orig	2026-11-17 11:49:09 UTC
+++ device/vr/openxr/openxr_render_loop.h
@@ -38,7 +38,7 @@
 #include "third_party/openxr/src/include/openxr/openxr.h"
 #include "ui/gfx/geometry/rect_f.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/threading/thread.h"
 #endif
 
@@ -65,7 +65,7 @@ class XRThread : public base::android::JavaHandlerThre
       : base::android::JavaHandlerThread(name) {}
   ~XRThread() override = default;
 };
-#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class XRThread : public base::Thread {
  public:
   explicit XRThread(const char* name) : base::Thread(name) {}
@@ -282,7 +282,7 @@ class OpenXrRenderLoop : public XRThread,
   void OnWebXrTokenSignaled(int16_t frame_index,
                             std::vector<LayerId> updated_layers,
                             std::unique_ptr<gfx::GpuFence> gpu_fence);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnWebXrWritesFlushed(int16_t frame_index,
                             std::vector<LayerId> updated_layers);
 #endif
