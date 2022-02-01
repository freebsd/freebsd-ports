--- gpu/config/gpu_util.cc.orig	2021-12-31 00:57:34 UTC
+++ gpu/config/gpu_util.cc
@@ -795,7 +795,7 @@ bool EnableSwiftShaderIfNeeded(base::CommandLine* comm
       gpu_feature_info.status_values[GPU_FEATURE_TYPE_ACCELERATED_GL] !=
           kGpuFeatureStatusEnabled) {
     bool legacy_software_gl = true;
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
     // This setting makes WebGL run on SwANGLE instead of SwiftShader GL.
     legacy_software_gl = false;
 #endif
