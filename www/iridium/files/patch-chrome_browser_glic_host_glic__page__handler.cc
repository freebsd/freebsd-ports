--- chrome/browser/glic/host/glic_page_handler.cc.orig	2026-05-13 08:49:22 UTC
+++ chrome/browser/glic/host/glic_page_handler.cc
@@ -195,7 +195,7 @@ mojom::FormFactor GetGlicFormFactor(ui::DeviceFormFact
 constexpr mojom::Platform kPlatform = mojom::Platform::kMacOS;
 #elif BUILDFLAG(IS_WIN)
 constexpr mojom::Platform kPlatform = mojom::Platform::kWindows;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr mojom::Platform kPlatform = mojom::Platform::kLinux;
 #elif BUILDFLAG(IS_CHROMEOS)
 constexpr mojom::Platform kPlatform = mojom::Platform::kChromeOS;
