-- OpenColorIO 2.3+ changed GpuShaderDesc::getTexture to require a
-- TextureDimensions argument. Add it with a version guard.
-- Upstream: https://github.com/olive-editor/olive/pull/2294

--- app/render/renderer.cpp.orig
+++ app/render/renderer.cpp
@@ -240,9 +240,17 @@ bool Renderer::GetColorContext(const ColorTransformJob &color_job, Renderer::Co
       const char* sampler_name = nullptr;
       unsigned int width = 0, height = 0;
       OCIO::GpuShaderDesc::TextureType channel = OCIO::GpuShaderDesc::TEXTURE_RGB_CHANNEL;
+#if OCIO_VERSION_HEX >= 0x02030000
+      OCIO::GpuShaderDesc::TextureDimensions dimensions = OCIO::GpuShaderDesc::TEXTURE_2D;
+#endif
       OCIO::Interpolation interpolation = OCIO::INTERP_LINEAR;

-      shader_desc->getTexture(i, tex_name, sampler_name, width, height, channel, interpolation);
+      shader_desc->getTexture(i, tex_name, sampler_name, width, height, channel,
+#if OCIO_VERSION_HEX >= 0x02030000
+                              // OCIO::GpuShaderDesc::TextureDimensions
+                              dimensions,
+#endif
+                              interpolation);

       if (!tex_name || !*tex_name
           || !sampler_name || !*sampler_name
