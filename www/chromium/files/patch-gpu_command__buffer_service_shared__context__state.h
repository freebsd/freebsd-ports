--- gpu/command_buffer/service/shared_context_state.h.orig	2026-10-18 13:29:39 UTC
+++ gpu/command_buffer/service/shared_context_state.h
@@ -273,7 +273,7 @@ class GPU_GLES2_EXPORT SharedContextState
   gpu::MemoryTypeTracker* memory_type_tracker() {
     return &memory_type_tracker_;
   }
-#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA))
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD))
   ExternalSemaphorePool* external_semaphore_pool() {
     return external_semaphore_pool_.get();
   }
@@ -444,7 +444,7 @@ class GPU_GLES2_EXPORT SharedContextState
   base::Time last_gl_check_graphics_reset_status_;
   bool disable_check_reset_status_throttling_for_test_ = false;
 
-#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA))
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD))
   std::unique_ptr<ExternalSemaphorePool> external_semaphore_pool_;
 #endif
 
