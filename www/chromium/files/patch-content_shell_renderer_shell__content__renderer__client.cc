--- content/shell/renderer/shell_content_renderer_client.cc.orig	2026-03-13 06:02:14 UTC
+++ content/shell/renderer/shell_content_renderer_client.cc
@@ -56,7 +56,7 @@
 #include "components/surface_embed/renderer/create_plugin.h"
 #endif  // BUILDFLAG(ENABLE_SURFACE_EMBED)
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
     (defined(ARCH_CPU_X86_64) || defined(ARCH_CPU_ARM64))
 #define ENABLE_WEB_ASSEMBLY_TRAP_HANDLER_LINUX
 #include "base/debug/stack_trace.h"
