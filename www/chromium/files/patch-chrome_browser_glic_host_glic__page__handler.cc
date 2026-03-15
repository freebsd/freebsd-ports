--- chrome/browser/glic/host/glic_page_handler.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/glic/host/glic_page_handler.cc
@@ -156,7 +156,7 @@ namespace {
 constexpr mojom::Platform kPlatform = mojom::Platform::kMacOS;
 #elif BUILDFLAG(IS_WIN)
 constexpr mojom::Platform kPlatform = mojom::Platform::kWindows;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr mojom::Platform kPlatform = mojom::Platform::kLinux;
 #elif BUILDFLAG(IS_CHROMEOS)
 constexpr mojom::Platform kPlatform = mojom::Platform::kChromeOS;
