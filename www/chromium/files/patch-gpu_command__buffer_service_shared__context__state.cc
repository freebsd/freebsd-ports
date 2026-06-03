--- gpu/command_buffer/service/shared_context_state.cc.orig	2026-04-09 06:05:42 UTC
+++ gpu/command_buffer/service/shared_context_state.cc
@@ -61,7 +61,7 @@
 #include "gpu/vulkan/vulkan_implementation.h"
 #include "gpu/vulkan/vulkan_util.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "gpu/command_buffer/service/external_semaphore_pool.h"
 #endif
 
@@ -298,7 +298,7 @@ SharedContextState::SharedContextState(
   ) {
     if (vk_context_provider_) {
 #if BUILDFLAG(ENABLE_VULKAN) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
       external_semaphore_pool_ = std::make_unique<ExternalSemaphorePool>(this);
 #endif
     }
@@ -339,7 +339,7 @@ SharedContextState::~SharedContextState() {
   }
 
 #if BUILDFLAG(ENABLE_VULKAN) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
   external_semaphore_pool_.reset();
 #endif
 
