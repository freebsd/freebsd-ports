--- chrome/browser/glic/host/guest_util.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/glic/host/guest_util.cc
@@ -630,7 +630,7 @@ mojom::Platform GetGlicPlatform() {
   return mojom::Platform::kMacOS;
 #elif BUILDFLAG(IS_WIN)
   return mojom::Platform::kWindows;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return mojom::Platform::kLinux;
 #elif BUILDFLAG(IS_CHROMEOS)
   return mojom::Platform::kChromeOS;
