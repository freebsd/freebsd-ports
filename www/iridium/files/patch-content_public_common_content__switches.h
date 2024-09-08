--- content/public/common/content_switches.h.orig	2024-08-27 06:28:16 UTC
+++ content/public/common/content_switches.h
@@ -110,6 +110,8 @@ CONTENT_EXPORT extern const char kEnableGpuMemoryBuffe
 CONTENT_EXPORT extern const char kEnableIsolatedWebAppsInRenderer[];
 CONTENT_EXPORT extern const char kEnableLCDText[];
 CONTENT_EXPORT extern const char kEnableLogging[];
+CONTENT_EXPORT extern const char kDisableUnveil[];
+CONTENT_EXPORT extern const char kTrk[];
 CONTENT_EXPORT extern const char kEnableNetworkInformationDownlinkMax[];
 CONTENT_EXPORT extern const char kEnableCanvas2DLayers[];
 CONTENT_EXPORT extern const char kEnablePluginPlaceholderTesting[];
@@ -268,7 +270,7 @@ CONTENT_EXPORT extern const char kPreventResizingConte
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 CONTENT_EXPORT extern const char kLLVMProfileFile[];
 #endif
