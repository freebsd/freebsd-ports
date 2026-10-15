--- content/shell/renderer/shell_content_renderer_client.cc.orig	2026-08-31 10:59:09 UTC
+++ content/shell/renderer/shell_content_renderer_client.cc
@@ -56,7 +56,7 @@
 #include "media/base/media_switches.h"
 #endif
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
     (defined(ARCH_CPU_X86_64) || defined(ARCH_CPU_ARM64))
 #define ENABLE_WEB_ASSEMBLY_TRAP_HANDLER_LINUX
 #include "base/debug/stack_trace.h"
