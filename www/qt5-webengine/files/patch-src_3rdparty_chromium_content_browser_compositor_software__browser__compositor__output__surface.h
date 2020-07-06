--- src/3rdparty/chromium/content/browser/compositor/software_browser_compositor_output_surface.h.orig	2020-03-16 14:04:24 UTC
+++ src/3rdparty/chromium/content/browser/compositor/software_browser_compositor_output_surface.h
@@ -39,7 +39,7 @@ class CONTENT_EXPORT SoftwareBrowserCompositorOutputSu
   gfx::BufferFormat GetOverlayBufferFormat() const override;
   uint32_t GetFramebufferCopyTextureFormat() override;
   unsigned UpdateGpuFence() override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   void SetNeedsSwapSizeNotifications(
       bool needs_swap_size_notifications) override;
 #endif
@@ -55,7 +55,7 @@ class CONTENT_EXPORT SoftwareBrowserCompositorOutputSu
   base::TimeDelta refresh_interval_;
   ui::LatencyTracker latency_tracker_;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   bool needs_swap_size_notifications_ = false;
 #endif
 
