--- gpu/command_buffer/service/shared_image_factory.cc.orig	2022-06-17 14:20:10 UTC
+++ gpu/command_buffer/service/shared_image_factory.cc
@@ -50,7 +50,7 @@
 #endif
 #endif
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENABLE_VULKAN)
 #include "gpu/command_buffer/service/external_vk_image_factory.h"
 #include "gpu/command_buffer/service/shared_image_backing_factory_ozone.h"
@@ -86,7 +86,7 @@
 
 namespace gpu {
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) &&      \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_ASH) &&      \
     !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_CASTOS) && \
     BUILDFLAG(ENABLE_VULKAN)
 
@@ -387,7 +387,7 @@ SharedImageFactory::SharedImageFactory(
     factories_.push_back(std::move(external_vk_image_factory));
   }
 #elif defined(USE_OZONE)
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
     !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_CASTOS)
   // Desktop Linux, not ChromeOS.
   if (ShouldUseOzoneFactory()) {
