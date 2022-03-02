--- content/browser/gpu/gpu_data_manager_impl_private.cc.orig	2022-02-28 16:54:41 UTC
+++ content/browser/gpu/gpu_data_manager_impl_private.cc
@@ -1340,7 +1340,7 @@ void GpuDataManagerImplPrivate::AppendGpuCommandLine(
       break;
     case gpu::GpuMode::SWIFTSHADER: {
       bool legacy_software_gl = true;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       // This setting makes WebGL run on SwANGLE instead of SwiftShader GL.
       legacy_software_gl = false;
 #endif
