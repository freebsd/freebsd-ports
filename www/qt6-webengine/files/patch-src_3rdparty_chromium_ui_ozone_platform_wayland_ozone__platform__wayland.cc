--- src/3rdparty/chromium/ui/ozone/platform/wayland/ozone_platform_wayland.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/ui/ozone/platform/wayland/ozone_platform_wayland.cc
@@ -71,7 +71,7 @@
 #include "ui/ozone/platform/wayland/host/wayland_cursor_factory.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/platform/wayland/host/linux_ui_delegate_wayland.h"
 #endif
 
@@ -246,7 +246,7 @@ class OzonePlatformWayland : public OzonePlatform,
 
     supported_buffer_formats_ =
         connection_->buffer_manager_host()->GetSupportedBufferFormats();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     linux_ui_delegate_ =
         std::make_unique<LinuxUiDelegateWayland>(connection_.get());
 #endif
@@ -470,7 +470,7 @@ class OzonePlatformWayland : public OzonePlatform,
   DrmRenderNodePathFinder path_finder_;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<LinuxUiDelegateWayland> linux_ui_delegate_;
 #endif
 };
