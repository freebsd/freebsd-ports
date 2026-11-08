--- chromeos/ash/components/mojo_proxy/mojo_core/core/embedder/embedder.cc.orig	2026-08-13 16:48:13 UTC
+++ chromeos/ash/components/mojo_proxy/mojo_core/core/embedder/embedder.cc
@@ -37,7 +37,7 @@
 #include "chromeos/ash/components/mojo_proxy/mojo_core/core/node_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chromeos/ash/components/mojo_proxy/mojo_core/core/channel_linux.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
         // BUILDFLAG(IS_ANDROID)
@@ -79,7 +79,7 @@ void InitFeatures() {
   CHECK(base::FeatureList::GetInstance());
 
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(MOJO_LEGACY_USE_APPLE_CHANNEL)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   bool shared_mem_enabled = base::FeatureList::IsEnabled(kMojoUseEventFd);
   int num_pages = kMojoUseEventFdPages.Get();
   if (num_pages < 0) {
