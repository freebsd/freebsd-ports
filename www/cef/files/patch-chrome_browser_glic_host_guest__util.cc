--- chrome/browser/glic/host/guest_util.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/glic/host/guest_util.cc
@@ -453,7 +453,7 @@ mojom::Platform GetGlicPlatform() {
   return mojom::Platform::kMacOS;
 #elif BUILDFLAG(IS_WIN)
   return mojom::Platform::kWindows;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return mojom::Platform::kLinux;
 #elif BUILDFLAG(IS_CHROMEOS)
   return mojom::Platform::kChromeOS;
