--- mojo/core/embedder/configuration.h.orig	2026-10-18 13:29:39 UTC
+++ mojo/core/embedder/configuration.h
@@ -33,7 +33,7 @@ struct Configuration {
   // objects.
   bool force_direct_shared_memory_allocation = false;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // If `true` and this process delegates shared memory allocation to the
   // broker, unsafe regions (which never need a read-only handle) are still
   // created directly in this process. That takes memfd_create(), ftruncate()
