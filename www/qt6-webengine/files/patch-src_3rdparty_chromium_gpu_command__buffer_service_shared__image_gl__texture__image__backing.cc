--- src/3rdparty/chromium/gpu/command_buffer/service/shared_image/gl_texture_image_backing.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/gpu/command_buffer/service/shared_image/gl_texture_image_backing.cc
@@ -345,7 +345,7 @@ void GLTextureImageBacking::CreateEGLImage() {
 }
 
 void GLTextureImageBacking::CreateEGLImage() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE) || BUILDFLAG(IS_BSD)
   SharedContextState* shared_context_state = factory()->GetSharedContextState();
   ui::ScopedMakeCurrent smc(shared_context_state->context(),
                             shared_context_state->surface());
