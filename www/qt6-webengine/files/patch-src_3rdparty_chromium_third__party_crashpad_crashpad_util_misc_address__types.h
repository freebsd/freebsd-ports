--- src/3rdparty/chromium/third_party/crashpad/crashpad/util/misc/address_types.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/crashpad/crashpad/util/misc/address_types.h
@@ -25,7 +25,7 @@
 #include <mach/mach_types.h>
 #elif BUILDFLAG(IS_WIN)
 #include "util/win/address_types.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "util/linux/address_types.h"
 #elif BUILDFLAG(IS_FUCHSIA)
 #include <zircon/types.h>
@@ -55,7 +55,7 @@ using VMSize = WinVMSize;
 using VMAddress = WinVMAddress;
 using VMSize = WinVMSize;
 
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 
 using VMAddress = LinuxVMAddress;
 using VMSize = LinuxVMSize;
