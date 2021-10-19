--- gpu/config/gpu_util.cc.orig	2021-09-24 18:51:11 UTC
+++ gpu/config/gpu_util.cc
@@ -740,7 +740,7 @@ bool EnableSwiftShaderIfNeeded(base::CommandLine* comm
       gpu_feature_info.status_values[GPU_FEATURE_TYPE_ACCELERATED_GL] !=
           kGpuFeatureStatusEnabled) {
     bool legacy_software_gl = true;
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
     // This setting makes WebGL run on SwANGLE instead of SwiftShader GL.
     legacy_software_gl = false;
 #endif
