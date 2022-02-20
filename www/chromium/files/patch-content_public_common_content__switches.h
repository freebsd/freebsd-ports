--- content/public/common/content_switches.h.orig	2022-02-07 13:39:41 UTC
+++ content/public/common/content_switches.h
@@ -114,6 +114,7 @@ CONTENT_EXPORT extern const char kEnableBlinkTestFeatu
 CONTENT_EXPORT extern const char kEnableGpuMemoryBufferVideoFrames[];
 CONTENT_EXPORT extern const char kEnableLCDText[];
 CONTENT_EXPORT extern const char kEnableLogging[];
+CONTENT_EXPORT extern const char kDisableUnveil[];
 CONTENT_EXPORT extern const char kEnableNetworkInformationDownlinkMax[];
 CONTENT_EXPORT extern const char kEnableCanvas2DLayers[];
 CONTENT_EXPORT extern const char kEnableCanvasContextLostInBackground[];
@@ -276,7 +277,7 @@ CONTENT_EXPORT extern const char kRendererWaitForJavaD
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 #endif
 
