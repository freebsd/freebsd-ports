--- content/services/isolated_xr_device/xr_runtime_provider.cc.orig	2026-11-11 14:44:17 UTC
+++ content/services/isolated_xr_device/xr_runtime_provider.cc
@@ -21,7 +21,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "device/vr/openxr/windows/openxr_platform_helper_windows.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "device/vr/openxr/linux/openxr_platform_helper_linux.h"
 #endif
 #endif
@@ -133,7 +133,7 @@ void IsolatedXRRuntimeProvider::SetupPollingForDeviceC
 #if BUILDFLAG(IS_WIN)
     openxr_platform_helper_ =
         std::make_unique<device::OpenXrPlatformHelperWindows>();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     openxr_platform_helper_ =
         std::make_unique<device::OpenXrPlatformHelperLinux>();
 #endif
