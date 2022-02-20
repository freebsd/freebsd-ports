--- gpu/command_buffer/service/shared_image_factory.cc.orig	2022-02-07 13:39:41 UTC
+++ gpu/command_buffer/service/shared_image_factory.cc
@@ -34,11 +34,11 @@
 #include "ui/gl/gl_switches.h"
 #include "ui/gl/trace_util.h"
 
-#if defined(OS_LINUX) && defined(USE_OZONE) && BUILDFLAG(ENABLE_VULKAN)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE) && BUILDFLAG(ENABLE_VULKAN)
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 
-#if (defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_WIN)) && \
+#if (defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_WIN) || defined(OS_BSD)) && \
     BUILDFLAG(ENABLE_VULKAN)
 #include "gpu/command_buffer/service/external_vk_image_factory.h"
 #include "gpu/command_buffer/service/shared_image_backing_factory_angle_vulkan.h"
@@ -75,7 +75,7 @@
 
 namespace gpu {
 
-#if defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) &&            \
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !BUILDFLAG(IS_CHROMEOS_ASH) &&            \
     !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_CHROMECAST) && \
     BUILDFLAG(ENABLE_VULKAN)
 
@@ -173,7 +173,7 @@ SharedImageFactory::SharedImageFactory(
   // |gr_context_type|.
   if (gr_context_type_ == GrContextType::kVulkan) {
 #if BUILDFLAG(ENABLE_VULKAN)
-#if defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
     !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_CHROMECAST)
     // Desktop Linux, not ChromeOS.
     if (base::FeatureList::IsEnabled(features::kVulkanFromANGLE)) {
