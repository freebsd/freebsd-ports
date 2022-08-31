--- gpu/command_buffer/service/shared_image/gl_texture_image_backing.cc.orig	2022-08-31 12:19:35 UTC
+++ gpu/command_buffer/service/shared_image/gl_texture_image_backing.cc
@@ -254,7 +254,7 @@ void GLTextureImageBacking::InitializeGLTexture(
 }
 
 void GLTextureImageBacking::CreateEGLImage() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE) || BUILDFLAG(IS_BSD)
   SharedContextState* shared_context_state = factory()->GetSharedContextState();
   ui::ScopedMakeCurrent smc(shared_context_state->context(),
                             shared_context_state->surface());
