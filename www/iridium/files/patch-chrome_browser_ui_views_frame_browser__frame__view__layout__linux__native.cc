--- chrome/browser/ui/views/frame/browser_frame_view_layout_linux_native.cc.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/ui/views/frame/browser_frame_view_layout_linux_native.cc
@@ -18,7 +18,7 @@ BrowserFrameViewLayoutLinuxNative::~BrowserFrameViewLa
 
 ui::WindowFrameProvider* BrowserFrameViewLayoutLinuxNative::GetFrameProvider()
     const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = delegate_->IsTiled();
   const bool maximized = delegate_->IsMaximized();
 #else
