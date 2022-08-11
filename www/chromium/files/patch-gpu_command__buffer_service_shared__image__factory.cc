--- gpu/command_buffer/service/shared_image_factory.cc.orig	2022-07-22 17:30:31 UTC
+++ gpu/command_buffer/service/shared_image_factory.cc
@@ -50,7 +50,7 @@
 #endif
 #endif
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENABLE_VULKAN)
 #include "gpu/command_buffer/service/external_vk_image_factory.h"
 #include "gpu/command_buffer/service/shared_image_backing_factory_ozone.h"
@@ -86,7 +86,7 @@ namespace gpu {
 
 namespace {
 
-#if defined(USE_OZONE) && BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)
+#if defined(USE_OZONE) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS)
 
 bool ShouldUseExternalVulkanImageFactory() {
 #if BUILDFLAG(ENABLE_VULKAN)
@@ -381,7 +381,7 @@ SharedImageFactory::SharedImageFactory(
     factories_.push_back(std::move(external_vk_image_factory));
   }
 #elif defined(USE_OZONE)
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS)
   // Desktop Linux, not ChromeOS.
   if (ShouldUseOzoneFactory()) {
     auto ozone_factory =
