--- ui/gl/gl_context.cc.orig	2025-08-07 06:57:29 UTC
+++ ui/gl/gl_context.cc
@@ -159,7 +159,7 @@ bool GLContext::MakeCurrent(GLSurface* surface) {
     recorded_max_gles_version_if_feasible = true;
   }
 #elif (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-       BUILDFLAG(IS_WIN))
+       BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
   static bool recorded_emulated_gles_version = false;
   if (!recorded_emulated_gles_version) {
     base::UmaHistogramBoolean("GPU.ANGLECanEmulateGLES3",
@@ -526,7 +526,7 @@ bool GLContext::MakeVirtuallyCurrent(
   DCHECK(virtual_context->IsCurrent(surface));
 
   if (switched_real_contexts || virtual_context != current_virtual_context_) {
-#if DCHECK_IS_ON()
+#if DCHECK_IS_ON() && !BUILDFLAG(IS_BSD)
     GLenum error = glGetError();
     // Accepting a context loss error here enables using debug mode to work on
     // context loss handling in virtual context mode.
