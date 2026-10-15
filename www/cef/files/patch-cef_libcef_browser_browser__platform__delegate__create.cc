--- cef/libcef/browser/browser_platform_delegate_create.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/browser_platform_delegate_create.cc
@@ -21,7 +21,7 @@
 #elif BUILDFLAG(IS_MAC)
 #include "cef/libcef/browser/native/browser_platform_delegate_native_mac.h"
 #include "cef/libcef/browser/osr/browser_platform_delegate_osr_mac.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "cef/libcef/browser/native/browser_platform_delegate_native_linux.h"
 #include "cef/libcef/browser/osr/browser_platform_delegate_osr_linux.h"
 #else
@@ -39,7 +39,7 @@ std::unique_ptr<CefBrowserPlatformDelega
 #elif BUILDFLAG(IS_MAC)
   return std::make_unique<CefBrowserPlatformDelegateNativeMac>(
       window_info, background_color);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<CefBrowserPlatformDelegateNativeLinux>(
       window_info, background_color);
 #endif
@@ -55,7 +55,7 @@ std::unique_ptr<CefBrowserPlatformDelega
 #elif BUILDFLAG(IS_MAC)
   return std::make_unique<CefBrowserPlatformDelegateOsrMac>(
       std::move(native_delegate), use_shared_texture, use_external_begin_frame);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<CefBrowserPlatformDelegateOsrLinux>(
       std::move(native_delegate), use_shared_texture, use_external_begin_frame);
 #endif
