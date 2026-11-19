--- content/app/initialize_mojo_core.cc.orig	2026-11-19 12:25:27 UTC
+++ content/app/initialize_mojo_core.cc
@@ -48,7 +48,7 @@ void InitializeMojoCore() {
     config.force_direct_shared_memory_allocation = true;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Renderer and GPU processes create a lot of unsafe regions (data pipes,
     // large IPC payloads) and their seccomp policies allow the memfd
     // creation, sizing and sealing that base needs for one, so let them skip
