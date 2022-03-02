--- gpu/command_buffer/service/shared_image_factory.cc.orig	2022-02-28 16:54:41 UTC
+++ gpu/command_buffer/service/shared_image_factory.cc
@@ -34,11 +34,11 @@
 #include "ui/gl/gl_switches.h"
 #include "ui/gl/trace_util.h"
 
-#if BUILDFLAG(IS_LINUX) && defined(USE_OZONE) && BUILDFLAG(ENABLE_VULKAN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(USE_OZONE) && BUILDFLAG(ENABLE_VULKAN)
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENABLE_VULKAN)
 #include "gpu/command_buffer/service/external_vk_image_factory.h"
 #include "gpu/command_buffer/service/shared_image_backing_factory_angle_vulkan.h"
@@ -75,7 +75,7 @@
 
 namespace gpu {
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) &&          \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
     !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_CHROMECAST) && \
     BUILDFLAG(ENABLE_VULKAN)
 
@@ -200,7 +200,7 @@ SharedImageFactory::SharedImageFactory(
   // |gr_context_type|.
   if (gr_context_type_ == GrContextType::kVulkan) {
 #if BUILDFLAG(ENABLE_VULKAN)
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
     !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_CHROMECAST)
     // Desktop Linux, not ChromeOS.
     if (base::FeatureList::IsEnabled(features::kVulkanFromANGLE)) {
