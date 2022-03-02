--- gpu/config/gpu_util.cc.orig	2022-02-28 16:54:41 UTC
+++ gpu/config/gpu_util.cc
@@ -754,7 +754,7 @@ bool EnableSwiftShaderIfNeeded(base::CommandLine* comm
       gpu_feature_info.status_values[GPU_FEATURE_TYPE_ACCELERATED_GL] !=
           kGpuFeatureStatusEnabled) {
     bool legacy_software_gl = true;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     // This setting makes WebGL run on SwANGLE instead of SwiftShader GL.
     legacy_software_gl = false;
 #endif
