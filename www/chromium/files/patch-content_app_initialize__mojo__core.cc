--- content/app/initialize_mojo_core.cc.orig	2026-10-18 13:29:39 UTC
+++ content/app/initialize_mojo_core.cc
@@ -54,7 +54,7 @@ void InitializeMojoCore() {
         mojo::core::kMojoDirectSharedMemoryAllocation);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Renderer and GPU processes create a lot of unsafe regions (data pipes,
     // large IPC payloads) and their seccomp policies allow the memfd
     // creation, sizing and sealing that base needs for one, so let them skip
