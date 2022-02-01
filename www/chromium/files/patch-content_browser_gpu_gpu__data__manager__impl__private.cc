--- content/browser/gpu/gpu_data_manager_impl_private.cc.orig	2021-12-31 00:57:32 UTC
+++ content/browser/gpu/gpu_data_manager_impl_private.cc
@@ -1298,7 +1298,7 @@ void GpuDataManagerImplPrivate::AppendGpuCommandLine(
       break;
     case gpu::GpuMode::SWIFTSHADER: {
       bool legacy_software_gl = true;
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
       // This setting makes WebGL run on SwANGLE instead of SwiftShader GL.
       legacy_software_gl = false;
 #endif
