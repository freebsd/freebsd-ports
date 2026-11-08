--- chrome/browser/ui/webui/version/version_ui.cc.orig	2026-08-13 16:48:13 UTC
+++ chrome/browser/ui/webui/version/version_ui.cc
@@ -209,7 +209,7 @@ int VersionUI::VersionProcessorVariation() {
   return IDS_VERSION_UI_64BIT;
 #endif  // defined(ARCH_CPU_X86)
 #endif  // defined(ARCH_CPU_ARM64)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if defined(ARCH_CPU_X86_64)
   return IDS_VERSION_UI_64BIT_INTEL;
 #elif defined(ARCH_CPU_ARM64)
