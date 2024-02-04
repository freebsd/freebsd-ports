--- content/public/common/content_switches.h.orig	2024-02-04 14:46:08 UTC
+++ content/public/common/content_switches.h
@@ -115,6 +115,8 @@ CONTENT_EXPORT extern const char kEnableGpuMemoryBuffe
 CONTENT_EXPORT extern const char kEnableIsolatedWebAppsInRenderer[];
 CONTENT_EXPORT extern const char kEnableLCDText[];
 CONTENT_EXPORT extern const char kEnableLogging[];
+CONTENT_EXPORT extern const char kDisableUnveil[];
+CONTENT_EXPORT extern const char kTrk[];
 CONTENT_EXPORT extern const char kEnableNetworkInformationDownlinkMax[];
 CONTENT_EXPORT extern const char kEnableCanvas2DLayers[];
 CONTENT_EXPORT extern const char kEnablePluginPlaceholderTesting[];
@@ -265,7 +267,7 @@ CONTENT_EXPORT extern const char kRendererWaitForJavaD
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 CONTENT_EXPORT extern const char kLLVMProfileFile[];
 #endif
