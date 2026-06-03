--- mojo/core/embedder/features.h.orig	2025-12-05 10:12:50 UTC
+++ mojo/core/embedder/features.h
@@ -14,7 +14,7 @@
 namespace mojo {
 namespace core {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(MOJO_CORE_EMBEDDER_FEATURES)
 BASE_DECLARE_FEATURE(kMojoUseEventFd);
 
