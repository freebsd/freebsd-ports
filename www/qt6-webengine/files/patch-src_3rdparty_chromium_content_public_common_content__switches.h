--- src/3rdparty/chromium/content/public/common/content_switches.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/content/public/common/content_switches.h
@@ -117,6 +117,7 @@ CONTENT_EXPORT extern const char kEnableLogging[];
 CONTENT_EXPORT extern const char kEnableGpuMemoryBufferVideoFrames[];
 CONTENT_EXPORT extern const char kEnableLCDText[];
 CONTENT_EXPORT extern const char kEnableLogging[];
+CONTENT_EXPORT extern const char kDisableUnveil[];
 CONTENT_EXPORT extern const char kEnableNetworkInformationDownlinkMax[];
 CONTENT_EXPORT extern const char kEnableCanvas2DLayers[];
 CONTENT_EXPORT extern const char kEnablePluginPlaceholderTesting[];
@@ -267,7 +268,7 @@ CONTENT_EXPORT extern const char kRendererWaitForJavaD
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 #endif
 
